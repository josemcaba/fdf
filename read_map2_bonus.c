/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:26:53 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/19 10:20:39 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	fill_row(t_map *map, int y, char *nbrs[])
{
	int	x;

	x = 0;
	while (nbrs[x])
	{
		map->coord[x][y] = ft_atoi(nbrs[x]);
		free(nbrs[x]);
		x++;
	}
	free(nbrs);
}
