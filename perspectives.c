/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspectives.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:03:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/25 00:19:10 by jocaball         ###   ########.fr       */
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
	map->img = mlx_new_image(map->mlx, map->width, map->height);
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
	map->img = mlx_new_image(map->mlx, map->width, map->height);
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
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, 100, 100);
}

void	zoom_in(t_map *map)
{
	mlx_delete_image(map->mlx, map->img);
	map->scale += 1;
	set_dimensions(map);
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

void	up(t_map *map)
{
	mlx_delete_image(map->mlx, map->img);
	map->z_scale += 0.01;
	set_dimensions(map);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, 100, 100);
}

void	down(t_map *map)
{
	mlx_delete_image(map->mlx, map->img);
	map->z_scale -= 0.01;
	set_dimensions(map);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, 100, 100);
}