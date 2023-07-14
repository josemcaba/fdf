/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:55:42 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/13 00:41:13 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1024
# define HEIGHT 576
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_map
{
	int			**p;
	int			columns;
	int			rows;
	double		alpha;
	double		beta;
	int			scale;
	float		z_scale;
	int			x_max;
	int			y_max;
	int			x_min;
	int			y_min;
	int			width;
	int			height;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*string;
}	t_map;

typedef struct s_point 
{
  int x;
  int y;
}	t_point;

int		read_map(char *fname, t_map *map);
void	free_map(t_map *map);
void	fill_row(t_map *map, int y, char *nbrs[]);
void	measure_map(int fd, int *rows, int *columns);
void	set_dimensions(t_map *map);
void	ft_hook(void *param);
void	ft_draw(void *param);
void	set_isometric(t_map *map);
void	set_military(t_map *map);
void	set_cavalier(t_map *map);
void	zoom_out(t_map *map);
void	zoom_in(t_map *map);
#endif
