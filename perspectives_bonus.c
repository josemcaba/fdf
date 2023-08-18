/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspectives.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:03:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/18 15:54:05 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_isometric(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 6;
	mlx_delete_image(map->mlx, map->menu);
	map->menu = mlx_put_string(map->mlx, "ISOMETRIC PERSPECTIVE", 5, 5);
}

void	set_military(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 3;
	mlx_delete_image(map->mlx, map->menu);
	map->menu = mlx_put_string(map->mlx, "MILITARY PERSPECTIVE", 5, 5);
}

void	set_cavalier(t_map *map)
{
	map->alpha = 0;
	map->beta = M_PI / 4;
	mlx_delete_image(map->mlx, map->menu);
	map->menu = mlx_put_string(map->mlx, "CAVALIER PERSPECTIVE", 5, 5);
}

void	set_initial_scale(t_map *map)
{
	t_point	point;
	int		i;
	int		j;

	map->alpha = M_PI / 6;
	map->beta = M_PI / 3;
	while (map->width < (WIDTH - LEFT_MARGIN) && \
			map->height < (HEIGHT - 2 * UPPER_MARGIN))
	{
		map->scale += 0.1;
		reset_limits(map);
		i = -1;
		while (++i < map->columns)
		{
			j = -1;
			while (++j < map->rows)
			{
				point = translate_coord_to_point(map, i, j);
				update_limits(map, point);
			}
		}
		map->width = fdim(map->x_max, map->x_min) + 1;
		map->height = fdim(map->y_max, map->y_min) + 1;
	}
}

void	rotate(t_map *map, int direction)
{
	int	width;
	int	height;

	width = map->width / 2;
	height = map->height / 2;
	map->alpha += (direction * M_PI / 180) * 0.2;
	map->alpha = fmod(map->alpha, 2 * M_PI);
	map->beta -= (direction * M_PI / 180) * 0.2;
	map->beta = fmod(map->beta, 2 * M_PI);
	fill_points(map);
	map->img->instances[0].x += width - map->width / 2;
	map->img->instances[0].y += height - map->height / 2;
}
