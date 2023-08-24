/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:05:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/24 15:21:10 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "fdf_bonus.h"
#else
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
	char		*line;
	char		**nbrs;
	uint32_t	row;

	row = 0;
	while (row < map->rows)
	{
		line = get_next_line(fd);
		line[ft_strlen(line) - 1] = '\0';
		nbrs = ft_split(line, ' ');
		if (!nbrs)
		{
			close (fd);
			free(line);
			error_exit("ERROR: ft_split at read_map.c (line 44)", map);
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
		error_exit("ERROR: malloc at read_map.c (line 62)", map);
	map->point = malloc(map->columns * sizeof(t_point *));
	if (!map->point)
		error_exit("ERROR: malloc at read_map.c (line 65)", map);
	i = 0;
	while (i < map->columns)
	{
		map->coord[i] = ft_calloc(map->rows, sizeof(int));
		map->point[i] = malloc(map->rows * sizeof(t_point));
		if (!(map->coord[i]) || !(map->point[i]))
		{
			map->columns = i;
			error_exit("ERROR: malloc at read_map.c (lines 71, 72)", map);
		}
		i++;
	}
}

static void	measure_map(int fd, t_map *map)
{
	char		*line;
	uint32_t	wc;

	map->rows = 0;
	map->columns = 0;
	line = get_next_line(fd);
	while (line)
	{
		(map->rows)++;
		wc = (uint32_t)ft_wc(line, ' ');
		if (wc > map->columns)
			map->columns = wc;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map->columns == 0)
		error_exit("ERROR: Map file is empty", map);
	if ((map->columns == 1) && (map->rows == 1))
		error_exit("ERROR: Map file has only one point", map);
}

void	read_map_file(char *fname, t_map *map)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		error_exit("ERROR: Can not open the map file", map);
	measure_map(fd, map);
	alloc_map(map);
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		error_exit("ERROR: Can not re-open the map file", map);
	fill_coord(fd, map);
}
