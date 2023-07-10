/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:38:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/10 20:24:44 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i <= map->x_max)
	{
		free(map->p[i]);
		i++;
	}
	free(map->p);
}

int	main(int argc, char **argv)
{
	t_map	org_map;
	mlx_t	*mlx_ptr;

	if (argc != 2)
	{
		ft_printf("Please enter just one FDF MAP file\n");
		return (0);
	}
	if (read_map(argv[1], &org_map) == EXIT_FAILURE)
		return (0);
	ft_printf("x_max = %d\ty_max = %d\n", org_map.x_max, org_map.y_max);
	size_t	y, x;
	for (y = 0; y <= org_map.y_max; y++)
	{
		for (x = 0; x<= org_map.x_max; x++)
			ft_printf("%3d", org_map.p[x][y]);
		ft_printf("\n");
	};
	mlx_ptr = mlx_init(WIDTH, HEIGHT, "FdF by Jose M. Caballero", true);
	mlx_loop(mlx_ptr);
	free_map(&org_map);
}
