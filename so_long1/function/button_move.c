//#include "./minilibx-linux/mlx.h"
#include <mlx.h>
#include <stdio.h>
#include "../libft/libft.h"

#define HEIGHT 500
#define WIDTH 500
#define PLAYER_UP "./asset/player_up.xpm"
#define PLAYER_DOWN "./asset/player_down.xpm"
#define PLAYER_LEFT "./asset/player_left.xpm"
#define PLAYER_RIGHT "./asset/player_right.xpm"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*path;
	int		previous_key;
	int		img_height;
	int		img_width;
}			t_data;

int	button(int keycode, t_data *data)
{
	if (keycode == data->previous_key)
		return 0;
	if (keycode == 2)
	{
		data->path = PLAYER_RIGHT;
	}
	else if (keycode == 13)
	{
		data->path = PLAYER_UP;
	}
	else if (keycode == 1)
	{
		data->path = PLAYER_DOWN;
	}
	else if (keycode == 0)
	{
		data->path = PLAYER_LEFT;
	}
	data->previous_key = keycode;
	printf("Pressed %d\n", keycode);
	data->img = mlx_xpm_file_to_image(data->mlx, data->path, &data->img_width, &data->img_height);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 250, 250);
	return (0);
}

int main()
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "so_long");
	data.path = PLAYER_DOWN;
	data.img = mlx_xpm_file_to_image(data.mlx, data.path, &data.img_width, &data.img_height);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 250, 250);
	mlx_key_hook(data.win, button, &data);
	mlx_loop(data.mlx);
}