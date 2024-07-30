/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:15:05 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/30 18:16:18 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setting_up_sx_sy(t_draw *d, t_point *p2)
{
	if (d->x < (int)p2->x_proj)
		d->sx = 1;
	else
		d->sx = -1;
	if (d->y < (int)p2->y_proj)
		d->sy = 1;
	else
		d->sy = -1;
}

void	update_err_and_x(t_draw *d)
{
	d->err -= d->dy;
	d->x += d->sx;
}

void	update_err_and_y(t_draw *d)
{
	d->err += d->dx;
	d->y += d->sy;
}

void	set_up_zoom(t_proj *p)
{
	if (p->biggest < 15)
		p->zoom = 40;
	else if (p->biggest < 35)
		p->zoom = 27;
	else if (p->biggest < 60)
		p->zoom = 18;
	else if (p->biggest < 100)
		p->zoom = 12;
	else if (p->biggest < 200)
		p->zoom = 8;
	else if (p->biggest < 350)
		p->zoom = 5;
	else if (p->biggest < 500)
		p->zoom = 3;
	else
		p->zoom = 1;
}
