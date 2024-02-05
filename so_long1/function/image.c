//#include "./minilibx-linux/mlx.h"
#include <mlx.h>
#include <stdio.h>
#include "../libft/libft.h"

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
	path = "./asset/player_down.xpm";
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello World!");
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 500, 500);
	mlx_loop(mlx);
	return 0;
}