/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:56:05 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/24 17:00:12 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_points(t_mlx *v, t_point *point)
{
	int	i;

	i = 0;
	while (point[i].x != -1)
	{
		*(int *)(v->img_data + ((int)point[i].x_proj * (v->bpp / 8)) + ((int)point[i].y_proj * v->size_line)) = point[i].color;
		i++;
	}
}
