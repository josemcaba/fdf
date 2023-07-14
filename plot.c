/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/13 01:06:12 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_points(void *param)
{
	t_map	*map;
	int		i;
	int		j;
	int		x;
	int		y;

	map = param;
	i = 0;
	while (i < map->columns)
	{
		j = 0;
		while (j < map->rows)
		{
			x = (i * cos(map->alpha) - j * cos(map->beta)) * map->scale;
			y = (i * sin(map->alpha) + j * sin(map->beta) - \
				map->p[i][j] * map->z_scale) * map->scale;
			x = x - map->x_min;
			y = y - map->y_min;
			mlx_put_pixel(map->img, x, y, 0xaaaaaa);
			j++;
		}
		i++;
	}
}

void 	plot_segment(t_point p1, t_point p2, t_map *map) 
{
	float		m;
	float		n;
	t_point	*points;

	m = (p2.y - p1.y) / (p2.x - p1.x);
	n = p1.y - (m * p1.x);
	while (++p1.x < p2.x)
  	{
		p1.y = m * p1.x + n;
  		mlx_put_pixel(map->img, p1.x, p1.y, 0xaaaaaa);
	}    
}
