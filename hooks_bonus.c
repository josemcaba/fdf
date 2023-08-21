/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/19 14:32:32 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	render_img(void *param)
{
	t_map	*map;

	map = param;
	fill_points(map);
	mlx_resize_image(map->img, map->width, map->height);
	ft_memset(map->img->pixels, 0, map->img->width * \
				map->img->height * sizeof(int));
	plot_grid(map);
	if (map->triangles)
		plot_triangles(map);
}

static void	pressed_keys_2(t_map	*map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->img->instances[0].y -= 3;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->img->instances[0].y += 3;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->img->instances[0].x -= 3;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->img->instances[0].x += 3;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_T))
		map->triangles = 1;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		map->triangles = 0;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_L))
		rotate(map, -1);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_R))
		rotate(map, +1);
	render_img(map);
}

void	pressed_keys(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_1))
		set_isometric(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_2))
		set_military(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_3))
		set_cavalier(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_KP_SUBTRACT))
		map->scale /= 1.01;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_KP_ADD))
		map->scale *= 1.01;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_U))
		map->z_scale += 0.002;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		map->z_scale -= 0.002;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_P))
		map->constant_color = 0;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_C))
		map->constant_color = 1;
	else
		pressed_keys_2(map);
}

