/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/07 16:52:02 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	open_new_window(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, \
			"FdF by Jose M. Caballero", true);
	if (!map->mlx)
	{
		ft_printf("Can not open a new window.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	init_map(char *fname, t_map *map)
{
	map->columns = 0;
	map->rows = 0;
	map->scale = 1;
	map->z_scale = 0.085;
	map->color = 0xaaaaaa;
	map->triangles = 0;
	map->img = NULL;
	map->string = NULL;
	if (read_map_file(fname, map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	set_menu(map);
	set_isometric_init(map);
	return (EXIT_SUCCESS);
}

void	free_map(t_map *map, int n_points)
{
	int	i;

	i = 0;
	while (i < map->columns)
	{
		free(map->coord[i]);
		i++;
	}
	free(map->coord);
	while (n_points)
	{
		n_points--;
		free(map->point[n_points]);
	}
	free(map->point);
}

int	main(int argc, char **argv)
{
	t_map		map;

	if (argc != 2)
	{
		ft_printf("Please enter just one FDF MAP file.\n");
		return (EXIT_FAILURE);
	}
	if (open_new_window(&map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_map(argv[1], &map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	mlx_loop_hook(map.mlx, fill_points, &map);
	mlx_loop_hook(map.mlx, plot_grid, &map);
	mlx_loop_hook(map.mlx, pressed_keys, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_map(&map, map.columns);
	return (EXIT_SUCCESS);
}
