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

void	translate(t_map *org, t_map *dst, int alpha, int beta)
{
	ssize_t	x;
	ssize_t	y;
	size_t	i;
	size_t	j;

	(void)dst;
	i = 0;
	while (i <= org->x_max)
	{
		j = 0;
		while (j <= org->y_max)
		{
			x = i * cos(alpha) - j * cos(beta);
			y = i * sin(alpha) + j * sin(beta) - org->p[x][y];
			j++;
		}
		i++;
	}
}
