/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:03:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/11 16:57:33 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_map *map)
{
	map->scale += 1;
	fill_points(map);
	mlx_resize_image(map->img, map->width, map->height);
	plot_grid(map);
}

void	zoom_out(t_map *map)
{
	if (map->scale > 0)
		map->scale -= 1;
	fill_points(map);
	mlx_resize_image(map->img, map->width, map->height);
	plot_grid(map);
}

void	up(t_map *map)
{
	map->z_scale += 0.001;
	fill_points(map);
	mlx_resize_image(map->img, map->width, map->height);
	plot_grid(map);
}

void	down(t_map *map)
{
	map->z_scale -= 0.001;
	fill_points(map);
	mlx_resize_image(map->img, map->width, map->height);
	plot_grid(map);
}
