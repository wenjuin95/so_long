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
#define WALL "./asset/wall.xpm"

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*path;
	int		img_height;
	int		img_width;
}			t_data;

int main()
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "so_long");
	data.path = WALL;
	data.img = mlx_xpm_file_to_image(data.mlx, data.path, &data.img_width, &data.img_height);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 250, 250);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 282, 250);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 314, 250);
	mlx_loop(data.mlx);
}