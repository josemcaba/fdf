/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:26:53 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/12 14:51:31 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	measure_map(int fd, int *rows, int *columns)
{
	char	*line;

	*rows = 0;
	*columns = 0;
	line = get_next_line(fd);
	while (line)
	{
		(*rows)++;
		if ((int)ft_wc(line, ' ') > *columns)
			*columns = ft_wc(line, ' ');
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
		map->p[x][y] = ft_atoi(nbrs[x]);
		free(nbrs[x]);
		x++;
	}
	free(nbrs);
}
