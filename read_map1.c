/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:05:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/13 19:11:42 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fill_map(int fd, t_map *map)
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
			free(line);
			close (fd);
			return (EXIT_FAILURE);
		}
		fill_row(map, row, nbrs);
		row++;
		free(line);
	}
	close (fd);
	return (EXIT_SUCCESS);
}

int	alloc_points(t_map *map)
{
	int	i;

	map->point = malloc(map->columns * sizeof(t_point *));
	if (!map->point)
		return (EXIT_FAILURE);
	i = 0;
	while (i < map->columns)
	{
		map->point[i] = malloc(map->rows * sizeof(t_point));
		if (!(map->point[i]))
		{
			free_map(map, i);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	alloc_map(int fd, t_map *map)
{
	int	i;

	measure_map(fd, map);
	close(fd);
	if (!map->columns)
		return (EXIT_FAILURE);
	map->coord = malloc(map->columns * sizeof(int *));
	if (!map->coord)
		return (EXIT_FAILURE);
	i = 0;
	while (i < map->columns)
	{
		map->coord[i] = ft_calloc(map->rows, sizeof(int));
		if (!(map->coord[i]))
		{
			map->columns = i;
			free_map(map, 0);
			return (EXIT_FAILURE);
		}
		i++;
	}
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

int	read_map_file(char *fname, t_map *map)
{
	int	fd;

	fd = open_map_file(fname);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (alloc_map(fd, map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (alloc_points(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open_map_file(fname);
	if (fd < 0)
	{
		free_map(map, 0);
		return (EXIT_FAILURE);
	}
	if (fill_map(fd, map) == EXIT_FAILURE)
	{
		free_map(map, map->columns);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
