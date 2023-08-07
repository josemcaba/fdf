/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:35:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/07 17:07:59 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_menu(t_map *map)
{
	map->string = mlx_put_string(map->mlx, ">>> PERSPECTIVE <<<", 5, 60);
	map->string = mlx_put_string(map->mlx, "[1] Isometric", 5, 80);
	map->string = mlx_put_string(map->mlx, "[2] Military", 5, 100);
	map->string = mlx_put_string(map->mlx, "[3] Cavalier", 5, 120);
	map->string = mlx_put_string(map->mlx, ">>> GRID <<<", 5, 160);
	map->string = mlx_put_string(map->mlx, "[S] Squared", 5, 180);
	map->string = mlx_put_string(map->mlx, "[T] Triangulated", 5, 200);
	map->string = mlx_put_string(map->mlx, ">>> HEIGHT <<<", 5, 240);
	map->string = mlx_put_string(map->mlx, "[U] Up", 5, 260);
	map->string = mlx_put_string(map->mlx, "[D] Down", 5, 280);
	map->string = mlx_put_string(map->mlx, "[+] Zoom in", 5, 320);
	map->string = mlx_put_string(map->mlx, "[-] Zoom out", 5, 340);
	map->string = mlx_put_string(map->mlx, "[L] Rotate left", 5, 380);
	map->string = mlx_put_string(map->mlx, "[R] Rotate right", 5, 400);
	map->string = mlx_put_string(map->mlx, "[arrows] Move", 5, 440);
}
