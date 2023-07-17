/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/17 14:06:24 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hook(void *param)
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
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->img->instances[0].y -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->img->instances[0].y += 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->img->instances[0].x -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->img->instances[0].x += 5;
}

void	update_limits(t_map *map, int x, int y)
{
	map->x_max = fmax(map->x_max, x);
	map->x_min = fmin(map->x_min, x);
	map->y_max = fmax(map->y_max, y);
	map->y_min = fmin(map->y_min, y);
}

void	set_dimensions(t_map *map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	map->x_max = 0;
	map->x_min = 0;
	map->y_max = 0;
	map->y_min = 0;
	i = -1;
	while (++i < map->columns)
	{
		j = 0;
		while (j < map->rows)
		{
			x = ((double)i * cos(map->alpha) - (double)j * cos(map->beta)) * \
				map->scale;
			y = ((double)i * sin(map->alpha) + (double)j * sin(map->beta) - \
				(double)map->p[i][j] * map->z_scale) * map->scale;
			update_limits(map, x, y);
			j++;
		}
	}
	map->width = fdim(map->x_max, map->x_min) + 1;
	map->height = fdim(map->y_max, map->y_min) + 1;
}
