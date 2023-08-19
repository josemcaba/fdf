/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   achievement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:33:53 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/19 20:51:58 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_achievement(t_map *map)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png("cofre.png");
	image = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	mlx_image_to_window(map->mlx, image, 0, 0);
	map->menu = mlx_put_string(map->mlx, "Gomu Gomu Achievement", 260, 640);
}
