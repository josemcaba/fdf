/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/25 19:28:49 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pressed_keys_2(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->img->instances[0].y -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->img->instances[0].y += 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->img->instances[0].x -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->img->instances[0].x += 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_T))
		map->triangles = 1;
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		map->triangles = 0;
}

void	pressed_keys(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_1))
		set_isometric(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_2))
		set_military(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_3))
		set_cavalier(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_KP_SUBTRACT))
		zoom_out(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_KP_ADD))
		zoom_in(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_U))
		up(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		down(map);
	pressed_keys_2(map);
}
