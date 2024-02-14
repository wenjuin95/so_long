// #include "./minilibx-linux/mlx.h"
// #include <X11/X.h>
// #include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include "../libft/libft.h"

#define HEIGHT 1000
#define WIDTH 1000

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
}			t_data;

int button_press(int button, int x, int y)
{
	//mouse button 1 is left click, 2 is right click
	//it return the coordinate
	if (button == 1)
		printf("Left mouse button pressed at (%d, %d)!\n", x, y);
    else if (button == 3)
        printf("Right mouse button pressed at (%d, %d)!\n", x, y);
    return (0);
}

int main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hello world!");
	//for mouse
	mlx_mouse_hook(data.mlx_win, button_press, &data);
	mlx_loop(data.mlx);
}