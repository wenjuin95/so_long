// // #include "../minilibx-linux/mlx.h"
// #include <mlx.h>
// #include <stdio.h>
// #include "../libft/libft.h"
#include "so_long.h"


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
	int		img_height;
	int		img_width;
}			t_data;

int	button(int keycode, t_data *data)
{
	printf("Pressed %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->mlx);
	}
	return (0);
}

int f_move(t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, data->path, &data->img_width, &data->img_height);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 250, 250);
    if (ft_strcmp(data->path, PLAYER_DOWN) == 0)
    {
		data->path = PLAYER_RIGHT;
		sleep(1);
	} 
    else if (ft_strcmp(data->path, PLAYER_RIGHT) == 0)
    {
		data->path = PLAYER_UP;
		sleep(1);
	}    
    else if (ft_strcmp(data->path, PLAYER_UP) == 0)
    {
		data->path = PLAYER_LEFT;
		sleep(1);
	}    
    else
    {
		data->path = PLAYER_DOWN;
		sleep(1);
	}
	return 0;
}

int main()
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "so_long");
	data.path = PLAYER_DOWN;
	mlx_key_hook(data.win, button, &data);
	mlx_loop_hook(data.mlx, f_move, &data);
	mlx_loop(data.mlx);
}
