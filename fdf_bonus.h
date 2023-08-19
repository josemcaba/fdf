/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:55:42 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/19 20:45:47 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_H
# define WIDTH 1900
# define HEIGHT 700
# define LEFT_MARGIN 1000
# define UPPER_MARGIN 50
# define MENU_LM 750
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
	uint32_t	constant_color;
	uint32_t	base_color;
	uint32_t	*grad;
	int			triangles;
	int			xmouse;
	int			ymouse;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*menu;
}	t_map;

int			read_map_file(char *fname, t_map *map);
void		free_map(t_map *map, int n_points);
void		fill_row(t_map *map, int y, char *nbrs[]);
void		measure_map(int fd, t_map *map);
void		render_img(void *param);
void		pressed_keys(void *param);
void		fill_points(t_map *map);
void		plot_grid(t_map *map);
void		set_initial_scale(t_map *map);
void		set_isometric(t_map *map);
void		set_military(t_map *map);
void		set_cavalier(t_map *map);
t_point		translate_coord_to_point(t_map *map, int i, int j);
void		rotate(t_map *map, int direction);
void		reset_limits(t_map *map);
void		update_limits(t_map *map, t_point point);
int			steps_counter(t_point p1, t_point p2);
void		mouse_wheel(double xdelta, double ydelta, void *param);
void		mouse_move(double xpos, double ypos, void *param);
void		mouse_click(mouse_key_t b, action_t a, modifier_key_t m, void *p);
void		set_triadic_color(t_point *point, t_map *map);
uint32_t	*color_gradient(uint32_t init_color, uint32_t end_color, \
							int steps, t_map *map);
void		set_achievement(t_map *map);

#endif
