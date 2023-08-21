/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:05:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/21 14:14:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "fdf_bonus.h"
# else
# include "fdf.h"
#endif

static void	fill_row(t_map *map, int j, char *nbrs[])
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		map->coord[i][j] = ft_atoi(nbrs[i]);
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

static void	fill_coord(int fd, t_map *map)
{
	char	*line;
	char	**nbrs;
	int		row;

	row = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line[ft_strlen(line) - 1] = '\0';
		nbrs = ft_split(line, ' ');
		if (!nbrs)
		{
			close (fd);
			free(line);
			free_map(map);
			ft_error("ERROR: ft_split at read_map.c (line 42)");
		}
		fill_row(map, row, nbrs);
		free(line);
		row++;
	}
	close (fd);
}

static void	alloc_map(t_map *map)
{
	uint32_t	i;

	map->coord = malloc(map->columns * sizeof(int *));
	if (!map->coord)
		ft_error("ERROR: malloc at read_map.c (line 61)");
	map->point = malloc(map->columns * sizeof(t_point *));
	if (!map->point)
	{
		free(map->coord);
		ft_error("ERROR: malloc at read_map.c (line 64)");
	}
	i = 0;
	while (i < map->columns)
	{
		map->coord[i] = malloc(map->rows * sizeof(int));
		map->point[i] = malloc(map->rows * sizeof(t_point));
		if (!(map->coord[i]) || !(map->point[i]))
		{
			map->columns = i;
			free_map(map);
			ft_error("ERROR: malloc at read_map.c (lines 73, 74)");
		}
		i++;
	}
}

static void	measure_map(int fd, t_map *map)
{
	char	*line;

	map->rows = 0;
	map->columns = 0;
	line = get_next_line(fd);
	while (line)
	{
		(map->rows)++;
		if ((uint32_t)ft_wc(line, ' ') > map->columns)
			map->columns = ft_wc(line, ' ');
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map->columns == 0)
		ft_error("ERROR: Map file is empty");
}

void	read_map_file(char *fname, t_map *map)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		ft_error("ERROR: Can not open the map file");
	measure_map(fd, map);
	alloc_map(map);
	fd = open(fname, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		ft_error("ERROR: Can not re-open the map file");
	}
	fill_coord(fd, map);
}
