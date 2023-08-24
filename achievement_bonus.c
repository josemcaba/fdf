/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   achievement_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 20:33:53 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/24 15:17:49 by jocaball         ###   ########.fr       */
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
		ft_error("ERROR: mlx_load_png at achievement.c (line 21)");
	image = mlx_texture_to_image(map->mlx, texture);
	if (!image)
		ft_error("ERROR: mlx_texture_to_image at achievement.c (line 24)");
	mlx_delete_texture(texture);
	instance_index = mlx_image_to_window(map->mlx, image, 0, 0);
	if (instance_index < 0)
		ft_error("ERROR: mlx_image_to_window at achievement.c (line 28)");
	mlx_put_string(map->mlx, "Gomu Gomu Achievement", 260, 640);
}
