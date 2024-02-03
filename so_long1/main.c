#include "./minilibx-linux/mlx.h"

#include <stdio.h>

int main()
{
	void *mlx;
	void *win;
	void *img;
	void *path;
	int img_height;
	int img_width;

	path = "./asset/enermy.xpm";
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "Hello World!");
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 500, 500);
	mlx_loop(mlx);

	return 0;
}
