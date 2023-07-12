/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/10 23:23:31 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	mlx_t	*mlx_ptr;

	if (argc != 2)
	{
		ft_printf("Please enter just one FDF MAP file\n");
		return (0);
	}
	if (read_map(argv[1], &map) == EXIT_FAILURE)
		return (0);
	map.alpha = 0;
	map.beta = 45;
	map.scale = 100;
	map.z_scale = 1;
	translate(map);
	mlx_ptr = mlx_init(WIDTH, HEIGHT, "FdF by Jose M. Caballero", true);
	mlx_loop(mlx_ptr);
	free_map(&map);
}
