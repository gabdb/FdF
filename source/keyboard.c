/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:18:22 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/31 15:58:00 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_cross(t_mlx *v)
{
	clean_mlx(v);
	return (0);
}

void	clean_mlx(t_mlx *v)
{
	if (v->img_ptr)
		mlx_destroy_image(v->mlx_ptr, v->img_ptr);
	if (v->win_ptr)
		mlx_destroy_window(v->mlx_ptr, v->win_ptr);
	free(v->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	handle_esc(int keycode, t_mlx *v)
{
	if (53 == keycode)
		clean_mlx(v);
	return (0);
}
