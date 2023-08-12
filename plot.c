/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/11 17:49:20 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Calcula la ecuacion de la recta (y = mx + n) que pasa por los dos 
// puntos que se pasan como parámetros.
// Con esa ecuación se representan todos los puntos (pixeles) del
// intervalo cerrado [p1.x, p2.x]
// @param p1 Primer extremo del segmento
// @param p2 Segundo extremo del segmento
// @param *map Estrutura de datos del mapa
void	plot_line(t_point p1, t_point p2, t_map *map)
{
	double		m;
	double		n;
	uint32_t	y_prev;

	y_prev = p1.y;
	m = (p2.y - p1.y) / (p2.x - p1.x);
	n = p1.y - (m * p1.x);
	mlx_put_pixel(map->img, p1.x, p1.y, map->color);
	while (p1.x - p2.x)
	{
		if (p1.x < p2.x)
			p1.x++;
		else
			p1.x--;
		p1.y = (m * p1.x + n) + 0.5;
		mlx_put_pixel(map->img, p1.x, p1.y, map->color);
		while (++y_prev < p1.y)
			mlx_put_pixel(map->img, p1.x, y_prev, map->color);
		while (--y_prev > p1.y)
			mlx_put_pixel(map->img, p1.x, y_prev, map->color);
	}
}

void	plot_segment(t_point p1, t_point p2, t_map *map)
{
	if (p1.x == p2.x)
	{
		if (p1.y < p2.y)
			while (++p1.y < p2.y)
				mlx_put_pixel(map->img, p1.x, p1.y, map->color);
		else
			while (--p1.y > p2.y)
				mlx_put_pixel(map->img, p1.x, p1.y, map->color);
	}
	else
		plot_line(p1, p2, map);
}

void	plot_triangles(void *param)
{
	t_map	*map;
	int		i;
	int		j;
	int		color;

	map = param;
	color = map->color;
	if (!map->triangles)
		map->color = 0x0;
	j = -1;
	while (++j < map->rows - 1)
	{
		i = -1;
		while (++i < (map->columns - 1))
			plot_segment(map->point[i][j], map->point[i + 1][j + 1], map);
	}
	map->color = color;
}

void	plot_grid(void *param)
{
	t_map	*map;
	int		i;
	int		j;

	map = param;
	ft_memset(map->img->pixels, 0, map->img->width * \
	map->img->height * sizeof(int));
	plot_triangles(map);
	i = -1;
	while (++i < map->columns)
	{
		j = -1;
		while (++j < (map->rows - 1))
			plot_segment(map->point[i][j], map->point[i][j + 1], map);
	}
	j = -1;
	while (++j < map->rows)
	{
		i = -1;
		while (++i < (map->columns - 1))
			plot_segment(map->point[i][j], map->point[i + 1][j], map);
	}
}
