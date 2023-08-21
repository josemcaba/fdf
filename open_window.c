/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/21 14:57:16 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "fdf_bonus.h"
# else
# include "fdf.h"
#endif

void	free_map(t_map *map)
{
	uint32_t	i;

	i = 0;
	while (i < map->columns)
	{
		free(map->coord[i]);
		free(map->point[i]);
		i++;
	}
	free(map->coord);
	free(map->point);
}

static void	set_initial_scale(t_map *map)
{
	map->alpha = M_PI / 6;
	map->beta = M_PI / 6;
	map->scale = 0;
	map->width = 0;
	map->height = 0;
	while (map->width < (WIDTH - LEFT_MARGIN) && \
			map->height < (HEIGHT - 2 * UPPER_MARGIN))
	{
		map->scale += 0.1;
		fill_points(map);
	}
}

static void	open_window(t_map *map, char *str)
{
	int	idx;

	map->mlx = mlx_init(WIDTH, HEIGHT, str, true);
	if (!map->mlx)
	{
		free_map(map);
		ft_error("ERROR: mlx_init at fdf.c (line 49)");
	}
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	if (!map->img)
	{	
		mlx_close_window(map->mlx);
		mlx_terminate(map->mlx);
		free_map(map);
		ft_error("ERROR: mlx_new_image at fdf.c (line 55)");
	}
	idx = mlx_image_to_window(map->mlx, map->img, LEFT_MARGIN, UPPER_MARGIN);
	if (idx < 0)
	{
		mlx_close_window(map->mlx);
		mlx_terminate(map->mlx);
		free_map(map);
		ft_error("ERROR: mlx_image_to_window at fdf.c (line 33)");
	}
}
