/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:35:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/17 20:33:32 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_menu(t_map *map)
{
	map->menu = mlx_put_string(map->mlx, ">>> PERSPECTIVE <<<", 5, 60);
	map->menu = mlx_put_string(map->mlx, "[1] Isometric", 5, 80);
	map->menu = mlx_put_string(map->mlx, "[2] Military", 5, 100);
	map->menu = mlx_put_string(map->mlx, "[3] Cavalier", 5, 120);
	map->menu = mlx_put_string(map->mlx, ">>> GRID <<<", 5, 160);
	map->menu = mlx_put_string(map->mlx, "[S] Squared", 5, 180);
	map->menu = mlx_put_string(map->mlx, "[T] Triangulated", 5, 200);
	map->menu = mlx_put_string(map->mlx, ">>> HEIGHT <<<", 5, 240);
	map->menu = mlx_put_string(map->mlx, "[U] Up", 5, 260);
	map->menu = mlx_put_string(map->mlx, "[D] Down", 5, 280);
	map->menu = mlx_put_string(map->mlx, ">>> ZOOM <<<", 5, 320);
	map->menu = mlx_put_string(map->mlx, "[+] In", 5, 340);
	map->menu = mlx_put_string(map->mlx, "[-] Out", 5, 360);
	map->menu = mlx_put_string(map->mlx, "[Mouse wheel]", 5, 380);
	map->menu = mlx_put_string(map->mlx, ">>> MOVE<<<", 5, 420);
	map->menu = mlx_put_string(map->mlx, "[Arrows]", 5, 440);
	map->menu = mlx_put_string(map->mlx, "[Mouse left]", 5, 460);
	map->menu = mlx_put_string(map->mlx, ">>> ROTATE <<<", 5, 500);
	map->menu = mlx_put_string(map->mlx, "[L] Left", 5, 520);
	map->menu = mlx_put_string(map->mlx, "[R] Right", 5, 540);
	map->menu = mlx_put_string(map->mlx, "[Mouse right]", 5, 560);
	map->menu = mlx_put_string(map->mlx, ">>> COLOR <<<", 5, 600);
	map->menu = mlx_put_string(map->mlx, "[C] Constant", 5, 620);
	map->menu = mlx_put_string(map->mlx, "[P] Progressive", 5, 640);
	map->menu = mlx_put_string(map->mlx, "", 0, 0);
}
