/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/19 12:23:57 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	open_window(t_map *map, char *str)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, str, true);
	if (!map->mlx)
		ft_error("ERROR: mlx_init at fdf.c (line 17)");
}

static int	init_map(char *fname, t_map *map)
{
	map->columns = 0;
	map->rows = 0;
	map->width = 0;
	map->height = 0;
	map->scale = 0;
	map->z_scale = 0.08;
	map->base_color = 0xe3f50aff;
	map->img = NULL;
	if (read_map_file(fname, map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	set_initial_scale(map);
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
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
	if (map->point)
		free(map->point);
}

int	main(int argc, char **argv)
{
	t_map		map;

	if (argc != 2)
		ft_error("Please enter just ONE map file");
	open_window(&map, "FdF by Jose M. Caballero");
	if (init_map(argv[1], &map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	fill_points(&map);
	plot_grid(&map);
	mlx_loop_hook(map.mlx, pressed_keys, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_map(&map, map.columns);
	return (EXIT_SUCCESS);
}
