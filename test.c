#include "mlx.h"

int main(void)
{
	void	*mlx_ptr;
	void	*window;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	window = mlx_new_window(mlx_ptr, 500, 500, "FdF");
	if (!window)
		return (1);
	mlx_loop(mlx_ptr);

	return (0);
}