/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:55:42 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/25 01:06:54 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1000
# define HEIGHT 700
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_point
{
	double	x;
	double	y;
	int		color;
}	t_point;

typedef struct s_map
{
	int			**coord;
	t_point		**point;
	int			columns;
	int			rows;
	double		alpha;
	double		beta;
	double		scale;
	double		z_scale;
	int			x_max;
	int			y_max;
	int			x_min;
	int			y_min;
	int			width;
	int			height;
	int			color;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*string;
}	t_map;

int		read_map_file(char *fname, t_map *map);
void	free_map(t_map *map, int n_points);
void	fill_row(t_map *map, int y, char *nbrs[]);
void	measure_map(int fd, t_map *map);
void	set_dimensions(t_map *map);
void	ft_hook(void *param);
void	plot_points(void *param);
void	plot_grid(void *param);
void	set_isometric(t_map *map);
void	set_military(t_map *map);
void	set_cavalier(t_map *map);
void	zoom_out(t_map *map);
void	zoom_in(t_map *map);
void	up(t_map *map);
void	down(t_map *map);
t_point translate_coord_to_point(t_map *map, int i, int j);

#endif
