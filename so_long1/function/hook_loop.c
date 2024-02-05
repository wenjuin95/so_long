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
	void *mlx;
	void *mlx_win;
	int color;
} t_data;

int function (int keysym, t_data *data)
{
	printf("Pressed %d\n\n", keysym);
	sleep(1);

	if (keysym == 53)
	{
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx, data->mlx_win);
        free(data->mlx);
        exit(1);
	}
	return (0);
}

int chg_color(t_data *data)
{
	for (int h = 0; h < 1000; h++)
	{
		for (int v=0; v < 50; v++)
		mlx_pixel_put(data->mlx, data->mlx_win, 0+h, 500+v, data->color);
	}
	if (data->color == 0xFF0000)
		data->color = 0x00FF00;
	else if (data->color == 0x00FF00)
		data->color = 0x0000FF;
	else
		data->color = 0xFF0000;
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hello world!");
	//start with red
	data.color = 0xFF0000;
	mlx_key_hook(data.mlx_win, function, &data);
	//mlx_loop_hook is one hook that is triggered when there's no event processed.
    //Cool to have a continuous rendering on the screen
	//    mlx_loop_hook(data.mlx,
	//                change_color,
	//                &data);
	mlx_loop_hook(data.mlx, chg_color, &data);
	mlx_loop(data.mlx);
}