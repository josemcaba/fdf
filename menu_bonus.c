/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:30:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/20 12:30:17 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_menu(t_map *map)
{
	mlx_put_string(map->mlx, ">>> PERSPECTIVE <<<", MENU_LM, 50);
	mlx_put_string(map->mlx, "[1] Isometric", MENU_LM, 70);
	mlx_put_string(map->mlx, "[2] Military", MENU_LM, 90);
	mlx_put_string(map->mlx, "[3] Cavalier", MENU_LM, 110);
	mlx_put_string(map->mlx, ">>> GRID <<<", MENU_LM, 150);
	mlx_put_string(map->mlx, "[S] Squared", MENU_LM, 170);
	mlx_put_string(map->mlx, "[T] Triangulated", MENU_LM, 190);
	mlx_put_string(map->mlx, ">>> HEIGHT <<<", MENU_LM, 230);
	mlx_put_string(map->mlx, "[U] Up", MENU_LM, 250);
	mlx_put_string(map->mlx, "[D] Down", MENU_LM, 270);
	mlx_put_string(map->mlx, ">>> ZOOM <<<", MENU_LM, 310);
	mlx_put_string(map->mlx, "[+] In", MENU_LM, 330);
	mlx_put_string(map->mlx, "[-] Out", MENU_LM, 350);
	mlx_put_string(map->mlx, "[Mouse wheel]", MENU_LM, 370);
	mlx_put_string(map->mlx, ">>> MOVE <<<", MENU_LM, 410);
	mlx_put_string(map->mlx, "[Arrows]", MENU_LM, 430);
	mlx_put_string(map->mlx, "[Mouse left]", MENU_LM, 450);
	mlx_put_string(map->mlx, ">>> ROTATE <<<", MENU_LM, 490);
	mlx_put_string(map->mlx, "[L] Left", MENU_LM, 510);
	mlx_put_string(map->mlx, "[R] Right", MENU_LM, 530);
	mlx_put_string(map->mlx, "[Mouse right]", MENU_LM, 550);
	mlx_put_string(map->mlx, ">>> COLOR <<<", MENU_LM, 590);
	mlx_put_string(map->mlx, "[C] Constant", MENU_LM, 610);
	mlx_put_string(map->mlx, "[P] Progressive", MENU_LM, 630);
//	mlx_put_string(map->mlx, "", 0, 0);
}
