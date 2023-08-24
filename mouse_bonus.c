/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:06:55 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/24 14:44:32 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	mouse_wheel(double xdelta, double ydelta, void *param)
{
	t_map	*map;

	map = param;
	(void)xdelta;
	if (ydelta > 0)
		map->scale *= 1.02;
	if (ydelta < 0)
		map->scale /= 1.02;
}

void	mouse_move(double xpos, double ypos, void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_mouse_down(map->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		map->img->instances[0].x += ((xpos - map->xmouse));
		map->img->instances[0].y += ((ypos - map->ymouse));
		map->xmouse = xpos;
		map->ymouse = ypos;
	}
	if (mlx_is_mouse_down(map->mlx, MLX_MOUSE_BUTTON_RIGHT))
	{
		if (xpos > map->xmouse)
			rotate(map, -3);
		if (xpos < map->xmouse)
			rotate(map, +3);
		map->xmouse = xpos;
		map->ymouse = ypos;
	}
}

void	mouse_click(mouse_key_t b, action_t a, modifier_key_t m, void *p)
{
	t_map	*map;

	map = p;
	(void)m;
	if ((b == MLX_MOUSE_BUTTON_LEFT) && (a == MLX_PRESS))
		mlx_get_mouse_pos(map->mlx, &(map->xmouse), &(map->ymouse));
}
