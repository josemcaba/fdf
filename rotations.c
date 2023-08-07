/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:03:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/07 17:03:50 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Para borrar
#include <stdio.h>

void	rotate(t_map *map, int direction)
{
	map->alpha += direction * M_PI / 180;
	map->beta -= direction * M_PI / 180;
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
	mlx_delete_image(map->mlx, map->img);
	set_dimensions(map);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
}
