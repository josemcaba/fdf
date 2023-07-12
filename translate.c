/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/12 22:53:03 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(void *param)
{
	t_map	*map;
	int		i;
	int		j;
	int		x;
	int		y;

	map = param;
	i = 0;
	while (i < map->columns)
	{
		j = 0;
		while (j < map->rows)
		{
			x = (i * cos(map->alpha) - j * cos(map->beta)) * map->scale;
			y = (i * sin(map->alpha) + j * sin(map->beta) - \
				map->p[i][j] * map->z_scale) * map->scale;
			x = x - map->x_min;
			y = y - map->y_min;
			mlx_put_pixel(map->img, x, y, 0xaaaaaa);
			j++;
		}
		i++;
	}
}

void	ft_hook(void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_I))
		set_isometric(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_M))
		set_military(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_C))
		set_cavalier(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_KP_SUBTRACT))
		zoom_out(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_KP_ADD))
		zoom_in(map);
}

void	set_limits(t_map *map, int x, int y)
{
	if (x > map->x_max)
		map->x_max = x;
	if (x < map->x_min)
		map->x_min = x;
	if (y > map->y_max)
		map->y_max = y;
	if (y < map->y_min)
		map->y_min = y;
}

void	set_dimensions(t_map *map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	while (i < map->columns)
	{
		j = 0;
		while (j < map->rows)
		{
			x = (i * cos(map->alpha) - j * cos(map->beta)) * map->scale;
			y = (i * sin(map->alpha) + j * sin(map->beta) - \
				map->p[i][j] * map->z_scale) * map->scale;
			set_limits(map, x, y);
			j++;
		}
		i++;
	}
	map->width = map->x_max - map->x_min + 1;
	map->height = map->y_max - map->y_min + 1;
}
