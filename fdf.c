/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/12 23:11:37 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 6;
	map->scale = 10;
	map->z_scale = 1;
	map->x_max = 0;
	map->x_min = 0;
	map->y_max = 0;
	map->img = NULL;
	map->string = NULL;
}

int	main(int argc, char **argv)
{
	t_map		map;

	if (argc != 2)
	{
		ft_printf("Please enter just one FDF MAP file\n");
		return (EXIT_FAILURE);
	}
	if (read_map(argv[1], &map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_map(&map);
	set_dimensions(&map);
	map.mlx = mlx_init(map.width + 200, map.height + 200, \
			"FdF by Jose M. Caballero", true);
	set_isometric(&map);
	mlx_loop_hook(map.mlx, ft_draw, &map);
	mlx_loop_hook(map.mlx, ft_hook, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_map(&map);
	return (EXIT_SUCCESS);
}
