/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:44 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/17 16:53:25 by gnyssens         ###   ########.fr       */
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
	// cest de la merde pr linstant !!
	int	p;
	int	x;
	int	y;
	int	dx;
	int	dy;

	x = p1->x_proj;
	y = p1->y_proj;
	dx = p1->x_proj - p2->x_proj;
	dy = p1->y_proj - p2->y_proj;
	p = 2 * dy - dx;
	while (x != p2->x_proj && y != p2->y_proj)
	{
		if (p < 0)
		{
			//plot horizontal or vertical: *(int *)(v->img_data + ...) = p2->color;
			p = p + 2 * dy;
			//update x or y
		}
		else
		{
			//plot diagonal
			p = p + 2 * (dy - dy);
			//update x and y by 1
		}
	}
}

void	bresenham(t_point *point, t_mlx *v, int one_line_len, int number_lines)
{
	// loop through whole array of t_points.
	// each time a neighbor is found, a `draw_line` function is called,
	// with both t_points that ought to be connected as parameters.
}
