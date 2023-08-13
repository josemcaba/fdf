/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:52:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/13 17:05:30 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>
#include <stdlib.h>

int	*color_gradient(int init_color, int end_color, int steps)
{
	int				*gradient;
	t_color			color1;
	t_color			color2;
	t_delta_color	delta;
	int				i;

	gradient = (int *)malloc(sizeof(int) * (steps + 1));
	if (gradient == NULL)
		return (NULL);
	color1.red = init_color >> 16;
	color1.green = (init_color >> 8) & 0xFF;
	color1.blue = init_color & 0xFF;
	color2.red = (end_color & 0xFF0000) >> 16;
	color2.green = (end_color & 0x00FF00) >> 8;
	color2.blue = end_color & 0x0000FF;
	delta.red = (color2.red - color1.red) / (float)steps;
	delta.green = (color2.green - color1.green) / (float)steps;
	delta.blue = (color2.blue - color1.blue) / (float)steps;
	i = -1;
	while (++i <= steps)
		gradient[i] = ((color1.red + (int)(delta.red * i)) << 16) \
					| ((color1.green + (int)(delta.green * i)) << 8) \
					| (color1.blue + (int)(delta.blue * i));
	return (gradient);
}
