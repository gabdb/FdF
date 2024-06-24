/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:20:06 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/24 14:36:08 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_mlx	*v;


}

/*
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
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, &handle_esc, NULL);
	mlx_loop(mlx);

	return (0);
}
*/