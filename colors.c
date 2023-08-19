/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:52:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/19 13:57:32 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	steps_counter(t_point p1, t_point p2)
{
	int			steps;
	double		m;
	double		n;
	uint32_t	y_prev;

	m = (p2.y - p1.y) / (p2.x - p1.x);
	n = p1.y - (m * p1.x);
	steps = 0;
	while (p1.x != p2.x)
	{
		y_prev = p1.y;
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

static t_delta_color	get_delta(uint32_t init_color,
									uint32_t end_color, \
									int steps)
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
	delta.red = (color2.red - color1.red) / steps;
	delta.green = (color2.green - color1.green) / steps;
	delta.blue = (color2.blue - color1.blue) / steps;
	delta.alpha = (color2.alpha - color1.alpha) / steps;
	return (delta);
}

uint32_t	*color_gradient(uint32_t init_color, uint32_t end_color, \
							int steps)
{
	uint32_t		*gradient;
	t_color			color1;
	t_delta_color	delta;
	int				i;

	gradient = (uint32_t *)malloc(sizeof(uint32_t) * (steps + 1));
	if (gradient == NULL)
		return (NULL);
	color1.red = init_color >> 24;
	color1.green = (init_color >> 16) & 0xFF;
	color1.blue = (init_color >> 8) & 0xFF;
	color1.alpha = init_color & 0xFF;
	delta = get_delta(init_color, end_color, steps);
	i = -1;
	while (++i <= steps)
	{
		gradient[i] = ((color1.red + (int)(delta.red * i)) << 24) \
					| ((color1.green + (int)(delta.green * i)) << 16) \
					| ((color1.blue + (int)(delta.blue * i)) << 8) \
					| (color1.alpha + (int)(delta.alpha * 1));
	}
	return (gradient);
}

void	set_triadic_color(t_point *point, t_map *map)
{
	int	r;
	int	g;
	int	b;
	int	a;

	(*point).color = map->base_color;
	r = map->base_color >> 24;
	g = (map->base_color >> 16) & 0xff;
	b = (map->base_color >> 8) & 0xff;
	a = map->base_color & 0xff;
	if ((*point).h == map->h_max)
		(*point).color = g << 24 | b << 16 | r << 8 | a;
	if ((*point).h == map->h_min)
		(*point).color = b << 24 | r << 16 | g << 8 | a;
}
