/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:56:05 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/08 16:22:18 by gnyssens         ###   ########.fr       */
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
