/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/19 12:45:43 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	set_menu(t_map *map)
{
	map->menu = mlx_put_string(map->mlx, ">>> PERSPECTIVE <<<", MENU_LM, 60);
	map->menu = mlx_put_string(map->mlx, "[1] Isometric", MENU_LM, 80);
	map->menu = mlx_put_string(map->mlx, "[2] Military", MENU_LM, 100);
	map->menu = mlx_put_string(map->mlx, "[3] Cavalier", MENU_LM, 120);
	map->menu = mlx_put_string(map->mlx, ">>> GRID <<<", MENU_LM, 160);
	map->menu = mlx_put_string(map->mlx, "[S] Squared", MENU_LM, 180);
	map->menu = mlx_put_string(map->mlx, "[T] Triangulated", MENU_LM, 200);
	map->menu = mlx_put_string(map->mlx, ">>> HEIGHT <<<", MENU_LM, 240);
	map->menu = mlx_put_string(map->mlx, "[U] Up", MENU_LM, 260);
	map->menu = mlx_put_string(map->mlx, "[D] Down", MENU_LM, 280);
	map->menu = mlx_put_string(map->mlx, ">>> ZOOM <<<", MENU_LM, 320);
	map->menu = mlx_put_string(map->mlx, "[+] In", MENU_LM, 340);
	map->menu = mlx_put_string(map->mlx, "[-] Out", MENU_LM, 360);
	map->menu = mlx_put_string(map->mlx, "[Mouse wheel]", MENU_LM, 380);
	map->menu = mlx_put_string(map->mlx, ">>> MOVE<<<", MENU_LM, 420);
	map->menu = mlx_put_string(map->mlx, "[Arrows]", MENU_LM, 440);
	map->menu = mlx_put_string(map->mlx, "[Mouse left]", MENU_LM, 460);
	map->menu = mlx_put_string(map->mlx, ">>> ROTATE <<<", MENU_LM, 500);
	map->menu = mlx_put_string(map->mlx, "[L] Left", MENU_LM, 520);
	map->menu = mlx_put_string(map->mlx, "[R] Right", MENU_LM, 540);
	map->menu = mlx_put_string(map->mlx, "[Mouse right]", MENU_LM, 560);
	map->menu = mlx_put_string(map->mlx, ">>> COLOR <<<", MENU_LM, 600);
	map->menu = mlx_put_string(map->mlx, "[C] Constant", MENU_LM, 620);
	map->menu = mlx_put_string(map->mlx, "[P] Progressive", MENU_LM, 640);
	map->menu = mlx_put_string(map->mlx, "", 0, 0);
}

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
	map->width = 0;
	map->height = 0;
	map->scale = 0;
	map->z_scale = 0.08;
	map->constant_color = 1;
	map->base_color = 0xe3f50aff;
	map->triangles = 0;
	map->img = NULL;
	map->menu = NULL;
	mlx_image_to_window(map->mlx, mlx_texture_to_image(map->mlx, mlx_load_png("COFRE.png")), 0, 0);
	set_menu(map);
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
	{
		ft_printf("Please enter just one FDF MAP file.\n");
		return (EXIT_FAILURE);
	}
	if (open_new_window(&map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_map(argv[1], &map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	set_isometric(&map);
	mlx_loop_hook(map.mlx, render_img, &map);
	mlx_loop_hook(map.mlx, pressed_keys, &map);
	mlx_scroll_hook(map.mlx, mouse_wheel, &map);
	mlx_mouse_hook(map.mlx, mouse_click, &map);
	mlx_cursor_hook(map.mlx, mouse_move, &map);
	mlx_loop(map.mlx);
	mlx_terminate(map.mlx);
	free_map(&map, map.columns);
	return (EXIT_SUCCESS);
}
