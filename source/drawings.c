/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:56:05 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/27 16:31:03 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_points(t_mlx *v, t_point *point)
{
	int	i;
	int	test; //SUPPRIMER

	i = 0;
	while (point[i].x != -1)
	{
		if ((int)point[i].x_proj < 1920 && (int)point[i].y_proj < 1080) //evidemment 1920 & 1080 juste taille d'la window actuelle
			*(int *)(v->img_data + ((int)point[i].x_proj * (v->bpp / 8)) + ((int)point[i].y_proj * v->size_line)) = point[i].color;
		i++;
	}
}

void	reduce_z(t_point *point, int z)
{
	int	i;

	i = 0;
	if (z < 40)
	{
		while (point[i].x != -1)
		{
			point[i].z /= 3;
			i++;
		}
	}
	else
	{
		while (point[i].x != -1)
		{
			point[i].z /= 6;
			i++;
		}
	}
}

void	re_arrange_z(t_point *point)
{
	int		i;
	t_point	*current;

	current = point;
	i = 0;
	while (current[i].x != -1)
	{
		if (ft_abs(current[i].z) >= 20)
		{
			reduce_z(point, ft_abs(current[i].z));
			return ;
		}
		i++;
	}
}

void	fill_in_proj(t_point *point, int number_lines, int one_line_len)
{
	t_proj	p;
	int		i;

	p.biggest = number_lines;
	if (one_line_len > number_lines)
		p.biggest = one_line_len;
	set_up_zoom(&p);
	re_arrange_z(point);
	i = 0;
	while (point[i].x != -1)
	{
		p.x = point[i].x * p.zoom;
		p.y = point[i].y * p.zoom;
		p.z = point[i].z * p.zoom / 2;
		point[i].x_proj = (p.x - p.y) * (sqrt(3) / 2);
		point[i].y_proj = ((p.x + p.y) / 2) - p.z;
		point[i].x_proj += 1920 / 2;
		point[i].y_proj += 950 / 2 - (p.zoom / 2) * one_line_len;
		i++;
	}
}
