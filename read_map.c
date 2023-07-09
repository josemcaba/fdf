/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:05:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/08 11:05:47 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	measure_map(int fd, size_t *rows, size_t *columns)
{
	char	*line;

	*rows = 0;
	*columns = 0;
	line = get_next_line(fd);
	while (line)
	{
		(*rows)++;
		if (ft_wc(line, ' ') > *columns)
			*columns = ft_wc(line, ' ');
		free(line);
		line = get_next_line(fd);
	}
}

void	free_map(t_map *map)
{
	while (map->x_max > 0)
	{
		free(map->p[map->x_max]);
		map->x_max--;
	}
	free(map->p);
}

int	alloc_map(int fd, t_map *map)
{
	size_t	rows;
	size_t	columns;
	size_t	i;

	measure_map(fd, &rows, &columns);
	close(fd);
	if (!columns)
		return (EXIT_FAILURE);
	map->p = ft_calloc(columns, sizeof(int *));
	if (!map->p)
		return (EXIT_FAILURE);
	map->y_max = rows - 1;
	i = 0;
	while (i < columns)
	{
		map->p[i] = ft_calloc(rows, sizeof(int));
		if (!(map->p[i]))
		{
			free_map(map);
			return (EXIT_FAILURE);
		}
		map->x_max = i;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	fill_row(t_map *map, int y, char *nbrs[])
{
	size_t	x;

	x = 0;
	while ((*nbrs)[x])
	{
		ft_printf("%s\n", nbrs[x]);
		map->p[x][y] = ft_atoi(nbrs[x]);
		free(nbrs[x]);
		x++;
	}
	free(nbrs[x]);
	free(nbrs);
}

int	fill_map(int fd, t_map *map)
{
	char	*line;
	char	**nbrs;
	size_t	row;

	row = 0;
	line = get_next_line(fd);
	ft_printf("Uno\n");
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		nbrs = ft_split(line, ' ');
		if (!nbrs)
		{
			free(line);
			close (fd);
			return (EXIT_FAILURE);
		}
		fill_row(map, row, nbrs);
		row++;
		line = get_next_line(fd);
		ft_printf("Dos\n");
	}
	close (fd);
	return (EXIT_SUCCESS);
}

int	open_map_file(char *fname)
{
	int		fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		ft_printf("Can not open the FDF MAP file.\n");
	return (fd);
}

int	read_map(char *fname, t_map *map)
{
	int	fd;

	fd = open_map_file(fname);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (alloc_map(fd, map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open_map_file(fname);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (fill_map(fd, map) == EXIT_FAILURE)
	{
		free_map(map);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
