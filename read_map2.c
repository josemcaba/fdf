/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:26:53 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/13 18:18:36 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	measure_map(int fd, t_map *map)
{
	char	*line;

	map->rows = 0;
	map->columns = 0;
	line = get_next_line(fd);
	while (line)
	{
		(map->rows)++;
		if ((int)ft_wc(line, ' ') > map->columns)
			map->columns = ft_wc(line, ' ');
		free(line);
		line = get_next_line(fd);
	}
}

int	set_color(int height)
{
	if (height == 0)
		return (0xff00ffff);
	return (0x00ff00ff);
}

void	fill_row(t_map *map, int y, char *nbrs[])
{
	int	x;

	x = 0;
	while (nbrs[x])
	{
		map->coord[x][y] = ft_atoi(nbrs[x]);
		map->point[x][y].h = map->coord[x][y];
		map->point[x][y].color = set_color(map->coord[x][y]);
		free(nbrs[x]);
		x++;
	}
	free(nbrs);
}
