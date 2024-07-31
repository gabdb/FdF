/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:24:18 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/31 15:57:30 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "get_next_line.h"
# ifdef __linux__
#  include "../mlx/mlx.h"
#  include <X11/keysym.h>
# endif
# ifdef __APPLE__
#  include "../mlx/mlx.h"
# endif

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// STRUCTURES

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
	float	x_proj;
	float	y_proj;
}			t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_mlx;

typedef struct s_proj
{
	float	x;
	float	y;
	float	z;
	int		zoom;
	int		biggest;
}			t_proj;

typedef struct s_draw
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}			t_draw;

typedef struct s_map
{
	int		*result;
	int		fd;
	int		len;
	int		count_line;
	char	*line;
}			t_map;

typedef struct s_pars
{
	char	**real_line;
	t_point	*result;
	char	*line;
	int		fd;
	int		i;
	int		j;
}			t_pars;

// PARSING
void		args_exit(void);
int			ft_count_words(char *s, char c);
void		color(t_point *point, char *map_point);
int			*check_map(int ac, char **argv);
t_point		*parsing(char *map, int total_length, int one_line_len);

// HELP_PARSING
int			index_base(char c, char *base);
int			my_atoi_base(char *str);

// KEYBOARD STUFF
int			handle_esc(int keycode, t_mlx *v);
void		clean_mlx(t_mlx *v);
int			handle_cross(t_mlx *v);

// DRAWINGS
void		draw_points(t_mlx *v, t_point *point);
void		fill_in_proj(t_point *point, int number_lines, int one_line_len);
void		re_arrange_z(t_point *point);
void		reduce_z(t_point *point, int z);

// DRAW LINES
void		bresenham(t_point *point, t_mlx *v, int one_line_len,
				int number_lines);
void		draw_line(t_point *p1, t_point *p2, t_mlx *v);
int			has_below_neighbor(t_point *point, int number_lines);
int			has_right_neighbor(t_point *point, int one_line_len);

// HELP
int			ft_abs(int a);

// CUT FUNCTIONS
void		setting_up_sx_sy(t_draw *d, t_point *p2);
void		update_err_and_x(t_draw *d);
void		update_err_and_y(t_draw *d);
void		set_up_zoom(t_proj *p);

// CUT AND FREE
void		free_line_exit(char *line);
void		free_result_exit(t_point *point);
void		free_line_result_exit(t_point *point, char *line);
void		free_double(char **line);

// MALLOC FREE
int			*protected_malloc(int count_line, int len);
t_point		*special_malloc(int length);
int			safe_open(char *map, t_point *result);
void		mega_free(char *line, char **real_line);

#endif