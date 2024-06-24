/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:18:22 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/24 14:18:48 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int handle_esc(int keycode, void *param)
{
	(void)param;
	if (53 == keycode)
		exit(EXIT_SUCCESS);
	return (0);
}