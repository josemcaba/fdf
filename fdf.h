/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:55:42 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/19 10:40:57 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1400
# define HEIGHT 900
# define LEFT_MARGIN 100
# define UPPER_MARGIN 100
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_point
{
	double		x;
	double		y;
	int			h;
	uint32_t	color;
}	t_point;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	alpha;
}	t_color;

typedef struct s_delta_color
{
	int	red;
	int	green;
	int	blue;
	int	alpha;
}	t_delta_color;

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
	int			h_min;
	int			h_max;
	int			width;
	int			height;
	uint32_t	base_color;
	uint32_t	*grad;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_map;

int			read_map_file(char *fname, t_map *map);
void		free_map(t_map *map, int n_points);
void		fill_row(t_map *map, int y, char *nbrs[]);
void		pressed_keys(void *param);
void		fill_points(t_map *map);
void		plot_grid(t_map *map);
void		set_initial_scale(t_map *map);
t_point		translate_coord_to_point(t_map *map, int i, int j);
void		reset_limits(t_map *map);
void		update_limits(t_map *map, t_point point);
int			steps_counter(t_point p1, t_point p2);
void		set_triadic_color(t_point *point, t_map *map);
uint32_t	*color_gradient(uint32_t init_color, uint32_t end_color, int steps);

#endif
