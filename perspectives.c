/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspectives.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:03:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/11 13:18:26 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_isometric(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 6;
	set_dimensions(map);
	mlx_delete_image(map->mlx, map->string);
	map->string = mlx_put_string(map->mlx, "Perspectiva isometrica", 5, 5);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
}

void	set_military(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 3;
	set_dimensions(map);
	mlx_delete_image(map->mlx, map->string);
	map->string = mlx_put_string(map->mlx, "Perspectiva militar", 5, 5);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
}

void	set_cavalier(t_map *map)
{
	map->alpha = 0;
	map->beta = M_PI / 4;
	set_dimensions(map);
	mlx_delete_image(map->mlx, map->string);
	map->string = mlx_put_string(map->mlx, "Perspectiva caballera", 5, 5);
	mlx_delete_image(map->mlx, map->img);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
}

void	set_isometric_init(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 3;
	while (map->width < (WIDTH - LEFT_MARGIN) && \
			map->height < (HEIGHT - 2 * UPPER_MARGIN))
	{
		map->scale += 0.1;
		set_dimensions(map);
	}
	set_isometric(map);
}
