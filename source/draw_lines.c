/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:44 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/22 15:28:32 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//ici Bresenham relier les points
int	has_right_neighbor(t_point *point, int one_line_len)
{
	if (point->x < one_line_len - 1)
		return (1);
	else
		return (0);
}

int	has_below_neighbor(t_point *point, int number_lines)
{
	if (point->y < number_lines - 1)
		return (1);
	else
		return (0);
}

void	draw_line(t_point *p1, t_point *p2, t_mlx *v)
{
	int	x; //structure a venir
	int	y;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = ft_abs(p2->x_proj - p1->x_proj);
	dy = ft_abs(p2->y_proj - p1->y_proj);
	err = dx - dy;
	x = p1->x_proj;
	y = p1->y_proj;
	if (x < p2->x_proj)
		sx = 1;
	else
		sx = -1;
	if (y < p2->y_proj)
		sy = 1;
	else
		sy = -1;
	while (1)
	{
		if (x >= 0 && x < 1920 && y >= 0 && y < 1080) //taille window a determiner
			*(int *)(v->img_data + (x * (v->bpp / 8)) + (y * v->size_line)) = p1->color;
		if (x > p2->x_proj - 2 && y >= p2->y_proj - 2)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
    		err -= dy;
        	x += sx;
        }
        if (e2 < dx)
		{
    		err += dx;
        	y += sy;
		}
	}
}


// loop through whole array of t_points.
// each time a neighbor is found, a `draw_line` function is called,
// with both t_points that ought to be connected as parameters.
void	bresenham(t_point *point, t_mlx *v, int one_line_len, int number_lines)
{
	t_point	*current;

	current = point;
	while (current->x != -1)
	{
		if (has_right_neighbor(current, one_line_len))
			draw_line(current, current + 1, v);
		if (has_below_neighbor(current, number_lines))
			draw_line(current, current + one_line_len, v);
		current += 1;
	}
}
