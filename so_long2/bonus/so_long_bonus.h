/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:53:31 by welow             #+#    #+#             */
/*   Updated: 2024/02/13 20:53:31 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
// # include "../minilibx-linux/mlx.h"

# define XPM_WIDTH 32
# define XPM_HEIGHT 32

# define WALL '1'
# define FLOOR '8'
# define PLAYER '6'
# define EXIT 'E'
# define COLLECT '7'
# define ENERMY '9'

# define IMG_W "asset/wall.xpm"
# define IMG_F "asset/floor.xpm"
# define IMG_ENE "asset/enermy.xpm"

# define IMG_E "asset/exit.xpm"
# define IMG_E2 "asset/exit2.xpm"

# define IMG_I "asset/item.xpm"
# define IMG_I2 "asset/item2.xpm"
# define IMG_I3 "asset/item3.xpm"
# define IMG_I4 "asset/item4.xpm"
# define IMG_I5 "asset/item5.xpm"

# define IMG_P "asset/player_down.xpm"
# define IMG_P_UP "asset/player_up.xpm"
# define IMG_P_LEFT "asset/player_left.xpm"
# define IMG_P_RIGHT "asset/player_right.xpm"

# ifdef __APPLE__
#  define ESC 53
#  define Q 12
#  define W 13
#  define S 1
#  define D 2
#  define A 0
# else
#  define ESC 65307
#  define Q 113
#  define W 119
#  define S 115
#  define D 100
#  define A 97
# endif

typedef struct s_enermy
{
	int		x;
	int		y;
}			t_enermy;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*player;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit;
	void	*enermy;
	int		map_height;
	int		map_width;
	int		image_h;
	int		image_w;
	int		c_count;
	int		p_count;
	int		e_count;
	int		ene_count;
	int		x_axis;
	int		y_axis;
	int		step;
	int		item_pos;
	int		frame;
	int		enermy_present;
	int		x_enermy;
	int		y_enermy;
}			t_data;

//error handling
void	check_input(char *av);
int		check_map(t_data *game);
void	free_all(char **map);
int		check_rec(char **map);
int		check_wall(char **map);
void	check_if_pec(t_data *game, int h, int w);
int		check_pec(t_data *game);
int		valid_map(t_data *game);

//read map content
char	**read_map(char *av);

//input_image
void	input_image(t_data *game);

//image to window
void	place_xpm_to_image(t_data *game);
int		put_to_win(t_data *game);

//put control
void	input_control(t_data *game);
int		free_game(t_data *game);

//key control
int		control(int keycode, t_data *game);
void	image_for_key(t_data *game, int keycode);
int		check_move(t_data *game, int x, int y);
int		move_up(t_data *game, int keycode);
int		move_down(t_data *game, int keycode);
int		move_left(t_data *game, int keycode);
int		move_right(t_data *game, int keycode);

//animation
int		animation(t_data *game);

//enermy
int		enermy_control(int keycode, t_data *game);

#endif