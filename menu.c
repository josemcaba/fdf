/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:35:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/17 11:05:39 by jocaball         ###   ########.fr       */
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
	map->menu = mlx_put_string(map->mlx, "[+] Zoom in", 5, 320);
	map->menu = mlx_put_string(map->mlx, "[-] Zoom out", 5, 340);
	map->menu = mlx_put_string(map->mlx, "[L] Rotate left", 5, 380);
	map->menu = mlx_put_string(map->mlx, "[R] Rotate right", 5, 400);
	map->menu = mlx_put_string(map->mlx, "[arrows] Move", 5, 440);
	map->menu = mlx_put_string(map->mlx, "[C] Color", 5, 480);
	map->menu = mlx_put_string(map->mlx, "[M] Mono\n", 5, 500);
	map->menu = mlx_put_string(map->mlx, "", 0, 0);
}
