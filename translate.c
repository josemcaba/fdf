/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/17 14:13:42 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	update_limits(t_map *map, t_point point)
{
	map->x_max = fmax(map->x_max, point.x);
	map->x_min = fmin(map->x_min, point.x);
	map->y_max = fmax(map->y_max, point.y);
	map->y_min = fmin(map->y_min, point.y);
	map->h_max = fmax(map->h_max, point.h);
	map->h_min = fmin(map->h_min, point.h);
}

t_point	translate_coord_to_point(t_map *map, int i, int j)
{
	t_point	point;
	double	k;

	k = map->coord[i][j] * map->z_scale;
	point.x = (i * cos(map->alpha) - j * cos(map->beta)) * map->scale;
	point.y = (i * sin(map->alpha) + j * sin(map->beta) - k) * map->scale;
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
	point.h = map->coord[i][j];
	return (point);
}

void	reset_limits(t_map *map)
{
	t_point	point;

	point = translate_coord_to_point(map, 0, 0);
	map->x_max = point.x;
	map->x_min = point.x;
	map->y_max = point.y;
	map->y_min = point.y;
	map->h_max = point.h;
	map->h_min = point.h;
}

void	zero_adjust(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->columns)
	{
		j = 0;
		while (j < map->rows)
		{
			map->point[i][j].x -= map->x_min;
			map->point[i][j].y -= map->y_min;
			map->point[i][j].h -= map->h_min;
			j++;
		}
	}
}

void	fill_points(t_map	*map)
{
	t_point	point;
	int		i;
	int		j;

	reset_limits(map);
	i = 0;
	while (i < map->columns)
	{
		j = 0;
		while (j < map->rows)
		{
			point = translate_coord_to_point(map, i, j);
			update_limits(map, point);
			map->point[i][j].x = point.x;
			map->point[i][j].y = point.y;
			map->point[i][j].h = point.h;
			j++;
		}
		i++;
	}
	map->width = fdim(map->x_max, map->x_min) + 1;
	map->height = fdim(map->y_max, map->y_min) + 1;
	zero_adjust(map);
}
