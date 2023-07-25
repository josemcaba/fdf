/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/25 00:11:32 by jocaball         ###   ########.fr       */
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
	if (mlx_is_key_down(map->mlx, MLX_KEY_U))
		up(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		down(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->img->instances[0].y -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->img->instances[0].y += 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->img->instances[0].x -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->img->instances[0].x += 5;
}

void	update_limits(t_map *map, t_point point)
{
	map->x_max = fmax(map->x_max, point.x);
	map->x_min = fmin(map->x_min, point.x);
	map->y_max = fmax(map->y_max, point.y);
	map->y_min = fmin(map->y_min, point.y);
}

t_point translate_coord_to_point(t_map *map, int i, int j)
{
	t_point point;

	point.x = (i * cos(map->alpha) - j * cos(map->beta)) * map->scale;
	point.y = (i * sin(map->alpha) + j * sin(map->beta) - map->coord[i][j] * \
				map->z_scale) * map->scale;
	if (point.x > 0)
		point.x += 0.5;
	else
		point.x -= 0.5;
	if (point.y > 0)
		point.y += 0.5;
	else
		point.y -= 0.5;
	point.x = (int)point.x;
	point.y = (int)point.y;
	return (point);
}

void	set_dimensions(t_map *map)
{
	t_point	point;
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
			point = translate_coord_to_point(map, i, j);
			update_limits(map, point);
			j++;
		}
	}
	map->width = fdim(map->x_max, map->x_min) + 1;
	map->height = fdim(map->y_max, map->y_min) + 1;
}
