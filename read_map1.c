/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:05:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/12 15:54:57 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->columns)
	{
		free(map->p[i]);
		i++;
	}
	free(map->p);
}

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

int	alloc_map(int fd, t_map *map)
{
	int	rows;
	int	columns;
	int	i;

	measure_map(fd, &rows, &columns);
	close(fd);
	if (!columns)
		return (EXIT_FAILURE);
	map->p = malloc(columns * sizeof(int *));
	if (!map->p)
		return (EXIT_FAILURE);
	map->rows = rows;
	i = 0;
	while (i < columns)
	{
		map->p[i] = ft_calloc(rows, sizeof(int));
		if (!(map->p[i]))
		{
			free_map(map);
			return (EXIT_FAILURE);
		}
		i++;
		map->columns = i;
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
	{
		free_map(map);
		return (EXIT_FAILURE);
	}
	if (fill_map(fd, map) == EXIT_FAILURE)
	{
		free_map(map);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
