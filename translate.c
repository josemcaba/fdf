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

void	translate(t_map map, double alpha, double beta, int scale)
{
	ssize_t	x;
	ssize_t	y;
	size_t	i;
	size_t	j;
	double	pi;

	alpha = (M_PI / 180) * alpha;
	beta = (M_PI / 180) * beta;
	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			x = (i * cos(alpha) - j * cos(beta)) * scale;
			y = (i * sin(alpha) + j * sin(beta) - map.p[i][j]) * scale;
			ft_printf("%d\t%d\n", x, y);
			i++;
		}
		j++;
	}
}
