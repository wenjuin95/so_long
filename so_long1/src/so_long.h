/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:36:58 by welow             #+#    #+#             */
/*   Updated: 2024/02/10 14:27:57 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx-linux/mlx.h"
# include <stdbool.h>

# define XPM_WIDTH 32
# define XPM_HEIGHT 32

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define ITEM 'C'
# define ENERMY 'I'

# define IMG_W "asset/wall.xpm"
# define IMG_F "asset/floor.xpm"
# define IMG_E "asset/exit.xpm"
# define IMG_ENE "asset/enermy.xpm"

# define IMG_I "asset/item.xpm"
# define IMG_I2 "asset/item2.xpm"
# define IMG_I3 "asset/item3.xpm"
# define IMG_I4 "asset/item4.xpm"
# define IMG_I5 "asset/item5.xpm"

# define IMG_P "asset/player_down.xpm"
# define IMG_P_UP "asset/player_up.xpm"
# define IMG_P_LEFT "asset/player_left.xpm"
# define IMG_P_RIGHT "asset/player_right.xpm"

// //mac
// # define ESC 53
// # define W 13
// # define S 1
// # define D 2
// # define A 0

//linux
# define ESC 65307
# define Q 113
# define W 119
# define S 115
# define D 100
# define A 97

typedef struct s_data
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		player_count;
	int		item_count;
	int		exit_count;
	int		x_axis;
	int		y_axis;
	int		step;
	int		items;

	char	**map;

	void	*floor;
	void	*wall;
	void	*player;
	void	*item;
	void	*exit;
	void	*mlx;
	void	*win;

	int		fps;
	int		item_pos;

	void 	*enermy;
	int		enermy_count;
}			t_data;

//animation
int		animation(t_data *game);

//check input
bool	check_format(char *av);
int		free_all(t_data *game);
void	check_input(int ac, char **av);

//check error
void	check_p_e_c(t_data *game);
void	check_wall(t_data *game);

//read the map for image
int		get_width_lenght(char *str);
int		add_line(t_data *game, char *line);
int		read_map_content(t_data *game, char **av);

//get image for win
void	place_xpm_to_image(t_data *game);
void	put_to_win(t_data *game);

//key control
void	image_for_key(t_data *game, int keycode);
int		control(int keycode, t_data *game);
int		check_move(t_data *game, int x, int y);
int		move_up(t_data *game, int keycode);
int		move_down(t_data *game, int keycode);
int		move_left(t_data *game, int keycode);
int		move_right(t_data *game, int keycode);
#endif