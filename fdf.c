/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/13 00:39:48 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_map(char *fname, t_map *map)
{
	if (read_map_file(fname, &map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map->scale = 10;
	map->z_scale = 1;
	map->color = 0xaaaaaa;
	map->img = NULL;
	map->string = NULL;
	set_dimensions(&map);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_map		map;

	if (argc != 2)
	{
		ft_printf("Please enter just one FDF MAP file\n");
		return (EXIT_FAILURE);
	}
	if (init_map(argv[1], &map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	map.mlx = mlx_init(WIDTH, HEIGHT, \
			"FdF by Jose M. Caballero", true);
	set_isometric(&map);
	mlx_loop_hook(map.mlx, ft_draw, &map);
	mlx_loop_hook(map.mlx, ft_hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_map(&map);
	return (EXIT_SUCCESS);
}
