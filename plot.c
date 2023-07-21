/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/17 15:03:43 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Calcula la ecuacion de la recta (y=mx+n) que pasa por los dos 
// puntos que se pasan como parámetros.
// Con esa ecuación se representan todos los puntos (pixeles) del
// intervalo abierto (p1.x, p2.x)
// @param p1 Primer extremo del segmento
// @param p2 Segundo extremo del segmento
// @param *map Estrutura de datos del mapa
void	plot_segment(t_point p1, t_point p2, t_map *map)
{
	double	m;
	double	n;

	m = (p2.y - p1.y) / (p2.x - p1.x);
	n = p1.y - (m * (double)p1.x);
	while (p1.x - p2.x)
	{
		if (p1.x < p2.x)
			p1.x++;
		else
			p1.x--;
		p1.y = (m * (double)p1.x + n) + 0.5;
//		ft_printf("(%d, %d)\n", p1.x, p1.y);
		mlx_put_pixel(map->img, p1.x, p1.y, map->color);
	}
}


void	plot_grid(void *param)
{
	t_map	*map;
	int		i;
	int		j;

	map = param;
	i = 0;
	while (i < map->columns)
	{
		j = 0;
		while (j < (map->rows - 1))
		{
			plot_segment(map->point[i][j], map->point[i][j + 1], map);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < (map->columns - 1))
		{
			ft_printf("(%d, %d)\n", map->point[i][j].x, map->point[i][j].y);
			plot_segment(map->point[i][j], map->point[i + 1][j], map);
			i++;
		}
		j++;
	}	
}


void	plot_points(void *param)
{
	t_map	*map;
	int		i;
	int		j;
	double	x;
	double	y;

	map = param;
	i = 0;
	while (i < map->columns)
	{
		j = 0;
		while (j < map->rows)
		{
			x = (i * cos(map->alpha) - j * cos(map->beta)) * map->scale;
			y = (i * sin(map->alpha) + j * sin(map->beta) - map->coord[i][j] * \
				map->z_scale) * map->scale;
			x = x - map->x_min;
			y = y - map->y_min;
			map->point[i][j].x = x + 0.5;
			map->point[i][j].y = y + 0.5;
			mlx_put_pixel(map->img, x, y, map->color);
			j++;
		}
		i++;
	}
}
