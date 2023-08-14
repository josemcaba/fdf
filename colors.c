/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:52:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/13 20:31:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
#include <stdlib.h>

int	steps_counter(t_point p1, t_point p2)
{
	int			steps;
	double		m;
	double		n;
	uint32_t	y_prev;

	y_prev = p1.y + 0.5;
	m = (p2.y - p1.y) / (p2.x - p1.x);
	n = p1.y - (m * p1.x);
	steps = 0;
	while (p1.x - p2.x)
	{
		if (p1.x < p2.x)
			p1.x++;
		else
			p1.x--;
		p1.y = (m * p1.x + n) + 0.5;
		steps++;
		while (++y_prev < p1.y)
			steps++;
		while (--y_prev > p1.y)
			steps++;
	}
	return (steps);
}

t_delta_color get_delta(int init_color, int end_color, int steps)
{
	t_color			color1;
	t_color			color2;
	t_delta_color	delta;

	color1.red = init_color >> 24;
	color1.green = (init_color >> 16) & 0xFF;
	color1.blue = (init_color >> 8) & 0xFF;
	color1.alpha = init_color & 0xFF;
	color2.red = end_color >> 24;
	color2.green = (end_color >> 16) & 0xFF;
	color2.blue = (end_color >> 8) & 0xFF;
	color2.alpha = end_color & 0xFF;
	delta.red = (color2.red - color1.red) / (float)steps;
	delta.green = (color2.green - color1.green) / (float)steps;
	delta.blue = (color2.blue - color1.blue) / (float)steps;
	delta.alpha = (color2.alpha - color1.alpha) / (float)steps;
	return (delta);
}

int	*color_gradient(int init_color, int end_color, int steps, t_map *map)
{
	int				*gradient;
	t_color			color1;
	t_delta_color	delta;
	int				i;

	gradient = (int *)malloc(sizeof(int) * (steps + 1));
	if (gradient == NULL)
		return (NULL);
	if (map->flat_color)
		ft_memset(gradient, end_color, steps + 1);
	else
	{
		color1.red = init_color >> 24;
		color1.green = (init_color >> 16) & 0xFF;
		color1.blue = (init_color >> 8) & 0xFF;
		color1.alpha = init_color & 0xFF;
		delta = get_delta(init_color, end_color, steps);
		i = -1;
		while (++i <= steps)
			gradient[i] = ((color1.red + (int)(delta.red * i)) << 24) \
						| ((color1.green + (int)(delta.green * i)) << 16) \
						| ((color1.blue + (int)(delta.blue * i)) << 8) \
						| (color1.alpha + (int)(delta.alpha * 1));
	}
	return (gradient);
}
