/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:20:06 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/31 16:09:21 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx	v;
	t_point	*point;
	int		*map_info;

	map_info = check_map(ac, av);
	if (!map_info)
		return (0);
	point = parsing(av[1], map_info[0] * map_info[1], map_info[1]);
	if (!point)
		exit(EXIT_FAILURE);
	fill_in_proj(point, map_info[0], map_info[1]);
	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, 1920, 1080, "FdF");
	v.img_ptr = mlx_new_image(v.mlx_ptr, 1920, 1080);
	v.img_data = mlx_get_data_addr(v.img_ptr, &v.bpp, &v.size_line, &v.endian);
	draw_points(&v, point);
	bresenham(point, &v, map_info[1], map_info[0]);
	free(map_info);
	free(point);
	mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.img_ptr, 0, 0);
	mlx_key_hook(v.win_ptr, handle_esc, &v);
	mlx_hook(v.win_ptr, 17, 0, handle_cross, &v);
	mlx_loop(v.mlx_ptr);
	return (0);
}
