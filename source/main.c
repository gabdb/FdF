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
#define WIDTH 800
#define HEIGHT 600

int main()
{
    void *mlx;
    void *win;
    void *img;
    char *img_data;
    int bpp;
    int size_line;
    int endian;
    int x, y;
    int color;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Gradient Example");

    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img_data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            color = (x * 255 / WIDTH) << 16 | (y * 255 / HEIGHT) << 8 | (x * y * 255 / (WIDTH * HEIGHT));
            *(int *)(img_data + (x * 4 + y * size_line)) = color;
        }
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);

    return 0;
}
*/

/*
int main(void)
{
	void	*mlx_ptr;
	void	*window;
	void	*image_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	window = mlx_new_window(mlx_ptr, 800, 800, "FdF");
	if (!window)
		return (1);
	int x = 200;
	int y = 200;
	while (x < 500 && y < 500)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, 0xFF00FF);
		x++;
		y++;
	}
	mlx_key_hook(window, handle_esc, NULL);
	mlx_loop(mlx_ptr);

	return (0);
}
*/