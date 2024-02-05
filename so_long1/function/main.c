//#include "./minilibx-linux/mlx.h"
#include <mlx.h>
#include <stdio.h>
#include "../libft/libft.h"

#define HEIGHT 1000
#define WIDTH 1000

int main()
{
	//learn how to open window with c
	void	*mlx;
	void	*mlx_win;
	//initialize the pointer
	mlx = mlx_init();
	if (mlx == NULL)
	{
		free(mlx);
		return (1);
	}
	//create a window
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "hello world");
	if (mlx_win == NULL)
	{
		free(mlx_win);
		return (1);
	}
	// maintain a loop to ensure  window will still be displayed on the screen.
	mlx_loop(mlx);
}