/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:03:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/11 17:52:39 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Para borrar
#include <stdio.h> //Para borrar

void	rotate(t_map *map, int direction)
{
	map->alpha += (direction * M_PI / 180) * 0.2;
	map->alpha = fmod(map->alpha, 2 * M_PI);
	map->beta -= (direction * M_PI / 180) * 0.2;
	map->beta = fmod(map->beta, 2 * M_PI);
	fill_points(map);
	mlx_resize_image(map->img, map->width, map->height);
	plot_grid(map);
}

void	rotate_points(t_map *map, int direction)
{
	int		i;
	int		j;
	double	k;
	double	di;
	double	dj;

	i = -1;
	while (++i < map->columns)
	{
		j = 0;
		while (j < map->rows)
		{
			map->point[i][j].theta += direction * M_PI / 180 * 5;
			di = map->point[i][j].r * cos(map->point[i][j].theta);
			dj = map->point[i][j].r * sin(map->point[i][j].theta);
			k = map->coord[i][j] * map->z_scale;
			map->point[i][j].x = (di * cos(map->alpha) - dj * cos(map->beta)) * map->scale;
			map->point[i][j].y = (di * sin(map->alpha) + dj * sin(map->beta) - k) * map->scale;
			if (map->point[i][j].x > 0)
				map->point[i][j].x += 0.5;
			else
				map->point[i][j].x -= 0.5;
			if (map->point[i][j].y > 0)
				map->point[i][j].y += 0.5;
			else
				map->point[i][j].y -= 0.5;
			map->point[i][j].x = (int)map->point[i][j].x;
			map->point[i][j].y = (int)map->point[i][j].y;
			j++;
		}
	}
	fill_points(map);
	mlx_resize_image(map->img, map->width, map->height);
	plot_grid(map);
}
