/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/21 14:29:48 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// @brief Calcula la ecuacion de la recta (y = mx + n) que pasa por los dos 
// puntos que se pasan como parámetros.
// Con esa ecuación se representan todos los puntos (pixeles) del
// intervalo cerrado [p1.x, p2.x]
// @param p1 Primer extremo del segmento
// @param p2 Segundo extremo del segmento
// @param *map Estrutura de datos del mapa
static void	plot_line(t_point p1, t_point p2, t_map *map)
{
	double		m;
	double		n;
	uint32_t	y_prev;
	int			i;

	m = (p2.y - p1.y) / (p2.x - p1.x);
	n = p1.y - (m * p1.x);
	i = -1;
	mlx_put_pixel(map->img, p1.x, p1.y, map->grad[++i]);
	while (p1.x != p2.x)
	{
		y_prev = p1.y;
		if (p1.x < p2.x)
			p1.x++;
		else
			p1.x--;
		p1.y = (m * p1.x + n) + 0.5;
		while (++y_prev < p1.y)
			mlx_put_pixel(map->img, p1.x, y_prev, map->grad[++i]);
		while (--y_prev > p1.y)
			mlx_put_pixel(map->img, p1.x, y_prev, map->grad[++i]);
		mlx_put_pixel(map->img, p1.x, p1.y, map->grad[++i]);
	}
}

static void	plot_vertical(t_point p1, t_point p2, t_map *map)
{
	uint32_t	i;

	i = -1;
	if (p1.y < p2.y)
		while (++p1.y < p2.y)
			mlx_put_pixel(map->img, p1.x, p1.y, map->grad[++i]);
	else
		while (--p1.y > p2.y)
			mlx_put_pixel(map->img, p1.x, p1.y, map->grad[++i]);
}

static void	plot_segment(t_point p1, t_point p2, t_map *map)
{
	int	steps;

	steps = steps_counter(p1, p2);
	if (steps == 0)
		return ;
	map->grad = color_gradient(p1.color, p2.color, steps, map);
	if (map->grad == NULL)
		error_exit("ERROR: malloc at color.c (line 97)", map);
	if (p1.x == p2.x)
		plot_vertical(p1, p2, map);
	else
		plot_line(p1, p2, map);
	free(map->grad);
}

void	plot_grid(t_map	*map)
{
	uint32_t	i;
	uint32_t	j;

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
