/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/21 15:04:00 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	plot_bonus(t_map *map)
{
	set_isometric(map);
	set_menu(map);
	set_achievement(map);
}

static void	load_map(char *fname, t_map *map)
{
	map->z_scale = 0.08;
	map->base_color = 0xe3f50aff;
	map->coord = NULL;
	map->mlx = NULL;
	map->constant_color = 0;
	map->triangles = 0;
	read_map_file(fname, map);
	set_initial_scale(map);
}

int	main(int argc, char **argv)
{
	t_map		map;
	bool		hook;

	if (argc != 2)
		ft_error("ERROR: Please enter just ONE map file");
	load_map(argv[1], &map);
	open_window(&map, "FdF by Jose M. Caballero");
	plot_bonus(&map);
	hook = mlx_loop_hook(map.mlx, pressed_keys, &map);
	if (hook)
	{
		mlx_scroll_hook(map.mlx, mouse_wheel, &map);
		mlx_mouse_hook(map.mlx, mouse_click, &map);
		mlx_cursor_hook(map.mlx, mouse_move, &map);
		mlx_loop(map.mlx);
	}
	else
		ft_putstr_fd("ERROR: mlx_loop_hook at fdf.c (line 91)\n", 2);
	free_map(&map);
//	mlx_delete_image(map.mlx, map.img);
//	mlx_terminate(map.mlx);
	return (!hook);
}
