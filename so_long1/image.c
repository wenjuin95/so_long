#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 1000
#define WIDTH 1000

int main()
{
	//this to learn how to put image
	void *mlx;
	void *win;
	void *img;
	void *path;
	int img_height;
	int img_width;
	//get the path
	path = "./asset/enermy.xpm";
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "Hello World!");
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 500, 500);
	mlx_loop(mlx);
	return 0;
}