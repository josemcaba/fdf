/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspectives.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:03:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/11 17:56:39 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_isometric(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 6;
	fill_points(map);
	mlx_resize_image(map->img, map->width, map->height);
	plot_grid(map);
	mlx_delete_image(map->mlx, map->menu);
	map->menu = mlx_put_string(map->mlx, "ISOMETRIC", 5, 5);
}

void	set_military(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 3;
	fill_points(map);
	mlx_resize_image(map->img, map->width, map->height);
	plot_grid(map);
	mlx_delete_image(map->mlx, map->menu);
	map->menu = mlx_put_string(map->mlx, "MILITARY", 5, 5);
}

void	set_cavalier(t_map *map)
{
	map->alpha = 0;
	map->beta = M_PI / 4;
	fill_points(map);
	mlx_resize_image(map->img, map->width, map->height);
	plot_grid(map);
	mlx_delete_image(map->mlx, map->menu);
	map->menu = mlx_put_string(map->mlx, "CAVALIER", 5, 5);
}

void	set_dimensions(t_map *map)
{
	t_point	point;
	int		i;
	int		j;

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
	set_isometric(map);
}
