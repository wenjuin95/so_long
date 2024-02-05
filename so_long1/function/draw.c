//#include "./minilibx-linux/mlx.h"
#include <mlx.h>
#include <stdio.h>
#include "../libft/libft.h"

#define HEIGHT 1000
#define WIDTH 1000

int main()
{
	//this to learn how to draw
	void	*mlx;
	void	*mlx_win;	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "hello world");
	//this nested loop for a line 
	//red
	for (int h = 0; h < 100; h++)
	{
		for (int v=0; v < 100; v++)
		mlx_pixel_put(mlx, mlx_win, 500+h, 500+v, 0xFF0000);
	}
	for (int h = 0; h < 100; h++)
	{
		for (int v=0; v < 100; v++)
		mlx_pixel_put(mlx, mlx_win, 500+h, 600+v, 0x00FF00);
	}	
	mlx_loop(mlx);
}