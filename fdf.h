/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:55:42 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/10 23:22:22 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1920
# define HEIGHT 1024
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_map
{
	int		**p;
	size_t	x_max;
	size_t	y_max;
}	t_map;

int		read_map(char *fname, t_map *map);
void	free_map(t_map *map);
void	fill_row(t_map *map, int y, char *nbrs[]);
void	measure_map(int fd, size_t *rows, size_t *columns);
#endif
