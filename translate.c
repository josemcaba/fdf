/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/12 19:09:08 by jocaball         ###   ########.fr       */
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
			if (map->x_min < 0)
				x = x - map->x_min;
			if (map->y_min < 0)
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
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
	{
		map->alpha -= (M_PI / 12);
		translate(map);
	}
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

void	translate(t_map *map)
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
