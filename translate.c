/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/11 15:37:00 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_limits(t_map *map, t_point point)
{
	map->x_max = fmax(map->x_max, point.x);
	map->x_min = fmin(map->x_min, point.x);
	map->y_max = fmax(map->y_max, point.y);
	map->y_min = fmin(map->y_min, point.y);
}

t_point	translate_coord_to_point(t_map *map, int i, int j)
{
	t_point	point;
	double	k;

	k = map->coord[i][j] * map->z_scale;
	point.x = (i * cos(map->alpha) - j * cos(map->beta)) * map->scale;
	point.y = (i * sin(map->alpha) + j * sin(map->beta) - k) * map->scale;
	point.r = sqrt(pow(i, 2) + pow(j, 2)) * map->scale;
	point.theta = atan2(j, i);
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
