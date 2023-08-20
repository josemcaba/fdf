/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspectives_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:03:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/19 20:56:42 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_isometric(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 6;
	mlx_delete_image(map->mlx, map->str);
	map->str = mlx_put_string(map->mlx, "ISOMETRIC PERSPECTIVE", \
								LEFT_MARGIN, 5);
}

void	set_military(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 3;
	mlx_delete_image(map->mlx, map->str);
	map->str = mlx_put_string(map->mlx, "MILITARY PERSPECTIVE", \
								LEFT_MARGIN, 5);
}

void	set_cavalier(t_map *map)
{
	map->alpha = 0;
	map->beta = M_PI / 4;
	mlx_delete_image(map->mlx, map->str);
	map->str = mlx_put_string(map->mlx, "CAVALIER PERSPECTIVE", \
								LEFT_MARGIN, 5);
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
