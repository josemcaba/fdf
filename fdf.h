/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:55:42 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/24 13:59:10 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1100
# define HEIGHT 700
# define LEFT_MARGIN 80
# define UPPER_MARGIN 80
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
	double	red;
	double	green;
	double	blue;
	double	alpha;
}	t_delta_color;

typedef struct s_map
{
	int			**coord;
	t_point		**point;
	uint32_t	columns;
	uint32_t	rows;
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
	uint32_t	constant_color;
	uint32_t	base_color;
	uint32_t	*grad;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_map;

void		read_map_file(char *fname, t_map *map);
void		set_initial_scale(t_map *map);
void		open_window(t_map *map, char *str);
void		free_map(t_map *map);
void		error_exit(char *str, t_map *map);
void		pressed_keys(void *param);
void		fill_points(t_map *map);
void		plot_grid(t_map *map);
uint64_t	steps_counter(t_point p1, t_point p2);
void		set_triadic_color(t_point *point, t_map *map);
uint32_t	*color_gradient(uint32_t init_color, uint32_t end_color, \
							uint64_t steps, t_map *map);

#endif
