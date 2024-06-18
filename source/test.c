#include "mlx.h"
#include <stdlib.h>

int handle_esc(int keycode, void *param)
{
	(void)param;
	if (53 == keycode)
		exit(EXIT_SUCCESS);
	return (0);
}

/*
int main(void)
{
	void	*mlx_ptr;
	void	*window;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;

	int		x;
	int		y;
	int		color;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	window = mlx_new_window(mlx_ptr, 800, 800, "FdF");
	if (!window)
		return (1);
	img_ptr = mlx_new_image(mlx_ptr, 400, 400);
	if (!img_ptr)
		return (1);
	img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);

	x = 100;
	y = 100;
	color = 0xFF00FF;
	while (x < 200 && y < 200)
	{
		*(int *)(img_data + (x * (bpp / 8)) + y * size_line) = color;
		x++;
		y++;
	}
	mlx_put_image_to_window(mlx_ptr, window, img_ptr, 0, 0);

	mlx_key_hook(window, handle_esc, NULL);
	mlx_loop(mlx_ptr);

	return (0);
}
*/
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