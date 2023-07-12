/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspectives.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:03:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/12 23:39:10 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_isometric(t_map *map)
{
	mlx_delete_image(map->mlx, map->string);
	mlx_delete_image(map->mlx, map->img);
	map->alpha = M_PI / 6;
	map->beta = M_PI / 6;
	set_dimensions(map);
	map->string = mlx_put_string(map->mlx, "Perspectiva isometrica", 5, 5);
	map->img = mlx_new_image(map->mlx, map->width + 100, map->height + 100);
	mlx_image_to_window(map->mlx, map->img, 100, 100);
}

void	set_military(t_map *map)
{
	mlx_delete_image(map->mlx, map->string);
	mlx_delete_image(map->mlx, map->img);
	map->alpha = M_PI / 6;
	map->beta = M_PI / 3;
	set_dimensions(map);
	map->string = mlx_put_string(map->mlx, "Perspectiva militar", 5, 5);
	map->img = mlx_new_image(map->mlx, map->width + 100, map->height + 100);
	mlx_image_to_window(map->mlx, map->img, 100, 100);
}

void	set_cavalier(t_map *map)
{
	mlx_delete_image(map->mlx, map->string);
	mlx_delete_image(map->mlx, map->img);
	map->alpha = 0;
	map->beta = M_PI / 4;
	set_dimensions(map);
	map->string = mlx_put_string(map->mlx, "Perspectiva caballera", 5, 5);
	map->img = mlx_new_image(map->mlx, map->width + 100, map->height + 100);
	mlx_image_to_window(map->mlx, map->img, 100, 100);
}

void	zoom_in(t_map *map)
{
	mlx_delete_image(map->mlx, map->img);
	map->scale += 1;
	set_dimensions(map);
	mlx_resize_image(map->img, map->width, map->height);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, 100, 100);
}

void	zoom_out(t_map *map)
{
	mlx_delete_image(map->mlx, map->img);
	if (map->scale > 0)
		map->scale -= 1;
	set_dimensions(map);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, 100, 100);
}
