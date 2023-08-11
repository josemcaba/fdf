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
	set_dimensions(map);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
}

void	zoom_out(t_map *map)
{
	if (map->scale > 0)
		map->scale -= 1;
	set_dimensions(map);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
}

void	up(t_map *map)
{
	map->z_scale += 0.001;
	set_dimensions(map);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
}

void	down(t_map *map)
{
	map->z_scale -= 0.001;
	set_dimensions(map);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
}
