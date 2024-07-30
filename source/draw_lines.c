/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:44 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/30 18:20:43 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	t_draw	d;

	d.dx = ft_abs((int)p2->x_proj - (int)p1->x_proj);
	d.dy = ft_abs((int)p2->y_proj - (int)p1->y_proj);
	d.err = d.dx - d.dy;
	d.x = (int)p1->x_proj;
	d.y = (int)p1->y_proj;
	setting_up_sx_sy(&d, p2);
	while (1)
	{
		if (d.x >= 0 && d.x < 1920 && d.y >= 0 && d.y < 1080)
			*(int *)(v->img_data + (d.x * (v->bpp / 8)) + (d.y
						* v->size_line)) = p1->color;
		if (d.x == (int)p2->x_proj && d.y == (int)p2->y_proj)
			break ;
		d.e2 = 2 * d.err;
		if (d.e2 > -d.dy)
			update_err_and_x(&d);
		if (d.e2 < d.dx)
			update_err_and_y(&d);
	}
}

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
		current++;
	}
}
