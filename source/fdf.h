/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:24:18 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/26 17:34:24 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
#ifdef __linux__
    # include <X11/keysym.h>
    # include "../mlx/mlx.h"
#endif
#ifdef __APPLE__
    # define XK_Escape 53
    # define XK_o      31
    # define XK_i      34 
    # define XK_Up     126
    # define XK_Down   125
    # define XK_Left   123
    # define XK_Right  124
    # define XK_x      7
    # define XK_y      16
    # define XK_z      6
    # define XK_Space  49
    # include "../mlx/mlx.h"
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

//STRUCTURES

typedef struct  s_point
{
    float   x;
    float   y;
	float   z;
	int	    color;
    float   x_proj;
    float   y_proj;
}               t_point;

typedef struct  s_mlx
{
    void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}               t_mlx;

typedef struct s_proj
{
	float	x;
	float	y;
	float	z;
	int		zoom;
	int		biggest;
}               t_proj;

typedef struct s_draw
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}               t_draw;

//PARSING
int		ft_count_words(char *s, char c);
void	handle_color(t_point *point, char *map_point);
int		*check_map(int ac, char **argv);
t_point	*parsing(char *map, int total_length, int one_line_len);

//HELP_PARSING
int	    index_base(char c, char *base);
int	    my_atoi_base(char *str);

//KEYBOARD STUFF
int     handle_esc(int keycode, void *param);

//DRAWINGS
void	draw_points(t_mlx *v, t_point *point);
void	fill_in_proj(t_point *point, int number_lines, int one_line_len);
void	re_arrange_z(t_point *point);
void	reduce_z(t_point *point, int z);

//DRAW LINES
void	bresenham(t_point *point, t_mlx *v, int one_line_len, int number_lines);
void	draw_line(t_point *p1, t_point *p2, t_mlx *v);
int	    has_below_neighbor(t_point *point, int number_lines);
int	    has_right_neighbor(t_point *point, int one_line_len);


//HELP
int     ft_abs(int a);

//CUT_FUNCTIONS
void	setting_up_sx_sy(t_draw *d, t_point *p2);
void    update_err_and_x(t_draw *d);
void	update_err_and_y(t_draw *d);
void	set_up_zoom(t_proj *p);

#endif