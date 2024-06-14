/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:24:18 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/14 18:02:29 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "../libft/libft.h"
#ifdef __linux__
    # include <X11/keysym.h>
    # include "../mlx_linux/mlx.h"
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

//PARSING

typedef struct  s_point
{
    int	x;
    int	y;
	int	z;
	int	color;
}               t_point;

#endif