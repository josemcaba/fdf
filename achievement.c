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
	int32_t			instance_index;

	texture = mlx_load_png("cofre.png");
	if (!texture)
		ft_error("ERROR: mlx_load_png at achievement.c (line 20)");
	image = mlx_texture_to_image(map->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		ft_error("ERROR: mlx_texture_to_image at achievement.c (line 24)");
	instance_index = mlx_image_to_window(map->mlx, image, 0, 0);
	if (instance_index < 0)
		ft_error("ERROR: mlx_image_to_window at achievement.c (line 28)");
	map->str = mlx_put_string(map->mlx, "Gomu Gomu Achievement", 260, 640);
	if (!map->str)
		ft_error("ERROR: mlx_put_string at achievement.c (line 31)");
}
