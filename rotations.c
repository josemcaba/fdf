/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:03:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/11 15:05:03 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Para borrar
#include <stdio.h>

void	rotate(t_map *map, int direction)
{
	map->alpha += (direction * M_PI / 180) * 0.2;
	map->beta -= (direction * M_PI / 180) * 0.2;
	if (map->alpha < 0)
	{
		map->beta += map->alpha;
		map->alpha = 0;
	}
	if (map->beta < 0)
	{
		map->alpha += map->beta;
		map->beta = 0;
	}
	printf("Alpha = %5.2f\n", map->alpha * 180 / M_PI);
	printf("Beta  = %5.2f\n\n", map->beta * 180 / M_PI);
	set_dimensions(map);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
}

void	rotate_points(t_map *map, int direction)
{
	int		i;
	int		j;
	int		k;
	double	di;
	double	dj;

	i = -1;
	while (++i < map->columns)
	{
		j = 0;
		while (j < map->rows)
		{
			map->point[i][j].theta += direction * M_PI / 180;
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
	set_dimensions(map);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
}
