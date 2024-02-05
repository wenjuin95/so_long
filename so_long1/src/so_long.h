/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:36:58 by welow             #+#    #+#             */
/*   Updated: 2024/02/05 23:01:57 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx-linux/mlx.h"

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define EXIT 'E'
# define ITEM 'C'

# define IMG_W "asset/wall.xpm"
# define IMG_F "asset/floor.xpm"
# define IMG_P "asset/player_down.xpm"
# define IMG_E "asset/exit.xpm"
# define IMG_I "asset/item.xpm"

//mac
# define ESC 53
# define W 13
# define S 1
# define D 2
# define A 0

// linux
// # define ESC 65307
// # define W 119
// # define S 115
// # define D 100
// # define A 97

typedef struct	s_data
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		player_count;
	int		column_count;
	int		exit_count;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		items;

	char	**map;

	void	*floor;
	void	*wall;
	void	*player;
	void	*item;
	void	*exit;
	void	*mlx;
	void	*win;
}			t_data;


#endif

