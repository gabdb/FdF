/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:56:05 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/08 17:21:16 by gnyssens         ###   ########.fr       */
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

// size[0] == number of lines et size[1] == one_line_len
void	fill_in_proj(t_point *point, int *size)
{
	int	i;
	float	x;
	float	y;
	float	z;
	int		zoom;

	if (size[0] * size[1] < 250)
		zoom = 20;
	else if (size[0] * size[1] < 3000)
		zoom = 10;
	else
		zoom = 5;
	i = 0;
	while (point[i].x != -1)
	{
		x = point[i].x * zoom;
		y = point[i].y * zoom;
		z = point[i].z * zoom;
		point[i].x_proj = (x - y) * (sqrt(3) / 2);
		point[i].y_proj = ((x + y) / 2) - z;
		point[i].x_proj += 1920 / 2;
		point[i].y_proj += 1080 / 2 - (zoom / 2) * size[1];
		i++;
	}
}
