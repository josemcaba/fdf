/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/07 21:11:03 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	o_map;
//	mlx_t	*mlx_ptr;
	
	if (argc != 2)
	{
		ft_printf("Please enter just one FDF MAP file\n");
		return (0);
	}
	if (read_map(argv[1], &o_map) == EXIT_FAILURE)
		return (0);
	ft_printf("x_max = %d\ty_max = %d\n", o_map.x_max, o_map.y_max);
	size_t	y, x;
	for (y = 0; y <= o_map.y_max; y++)
	{
		for (x = 0; x<= o_map.x_max; x++)
			ft_printf("%d ", o_map.p[x][y]);
		ft_printf("\n");
	}
//	mlx_ptr = mlx_init(WIDTH, HEIGHT, "FdF by Jose M. Caballero", true);
//	mlx_loop(mlx_ptr);
}
