/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:20:06 by gnyssens          #+#    #+#             */
/*   Updated: 2024/07/26 17:36:05 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//juste dessiner les points_proj
int main(int ac, char **av)
{
	t_mlx	v;
	t_point	*point;
	int		*map_info;
	int		one_line_len; //peut etre enlevé pr de la place
	int		number_lines; //same up

	map_info = check_map(ac, av);
	one_line_len = map_info[1];
	number_lines = map_info[0];
	point = parsing(av[1], number_lines * one_line_len, one_line_len);
	if (!point)
		exit(EXIT_FAILURE);
	printf("map size: %d\n", number_lines * one_line_len);
	fill_in_proj(point, number_lines, one_line_len);
	free(map_info);

	v.mlx_ptr = mlx_init();
	v.win_ptr = mlx_new_window(v.mlx_ptr, 1920, 1080, "FdF");
	v.img_ptr = mlx_new_image(v.mlx_ptr, 1920, 1080);
	v.img_data = mlx_get_data_addr(v.img_ptr, &v.bpp, &v.size_line, &v.endian);

	draw_points(&v, point);
	bresenham(point, &v, one_line_len, number_lines);
	write(1, "bresenham a marche\n", 19);
	free(point);
	mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.img_ptr, 0, 0);
	mlx_key_hook(v.win_ptr, handle_esc, NULL);
	mlx_loop(v.mlx_ptr);

	return (0);
}



/* //ancien test MLX avec Gradient GPT/yann
int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	int		color;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 700, 700, "Gradient Example");
	img = mlx_new_image(mlx, 700, 700);
	img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

	y = 0;
	while (y < 700)
	{
		x = 0;
		while (x < 700)
		{
			color = ((x * 255 / 700) << 16) | ((y * 255 / 700) << 8) | (x * y * 255 / (700 * 700));
            *(int *)(img_data + (x * (bpp / 8) + y * size_line)) = color;
			x++;.
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, &handle_esc, NULL);
	mlx_loop(mlx);

	return (0);
}
*/