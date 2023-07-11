/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:59:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/11 00:29:19 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(t_map map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	map.alpha = (M_PI / 180) * map.alpha;
	map.beta = (M_PI / 180) * map.beta;
	i = 0;
	while (i < map.width)
	{
		j = 0;
		while (j < map.height)
		{
			x = i * cos(alpha) - j * cos(beta);
			y = i * sin(alpha) + j * sin(beta) - map.p[i][j] * map.z_scale;
			x *= map.scale;
			y *= map.scale;
			ft_printf("%d\t%d\n", x, y);
			j++;
		}
		i++;
	}
}
