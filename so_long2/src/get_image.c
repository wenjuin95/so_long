/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:23:16 by welow             #+#    #+#             */
/*   Updated: 2024/02/06 20:23:16 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <assert.h>

void	place_xpm_to_image(t_data *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx, IMG_F,
			&game->image_w, &game->image_h);
	game->wall = mlx_xpm_file_to_image(game->mlx, IMG_W,
			&game->image_w, &game->image_h);
	game->player = mlx_xpm_file_to_image(game->mlx, IMG_P,
			&game->image_w, &game->image_h);
	game->exit = mlx_xpm_file_to_image(game->mlx, IMG_E,
			&game->image_w, &game->image_h);
	game->collect = mlx_xpm_file_to_image(game->mlx, IMG_I,
			&game->image_w, &game->image_h);
	game->enermy = mlx_xpm_file_to_image(game->mlx, IMG_ENE,
			&game->image_w, &game->image_h);
}

static void	position_player(t_data *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player,
		x * XPM_WIDTH, y * XPM_HEIGHT);
	game->x_axis = x;
	game->y_axis = y;
}

// static void	position_enermy(t_data *game, int x, int y)
// {
// 	mlx_put_image_to_window(game->mlx, game->win, game->enermy,
// 		x * XPM_WIDTH, y * XPM_HEIGHT);
// 	game->enermy_x = x;
// 	game->enermy_y = y;
// }

// static void	position_enermy(t_data *game, int x, int y)
// {
// 	t_enermy	*new_enermies;

// 	new_enermies = malloc((game->enermy_count + 1) * sizeof(t_enermy));
// 	if (new_enermies == NULL)
// 		return ;
// 	if (game->enermies != NULL)
// 	{
// 		ft_memcpy(new_enermies, game->enermies, game->enermy_count
// 			* sizeof(t_enermy));
// 		free(game->enermies);
// 	}
// 	game->enermies = new_enermies;
// 	game->enermies[game->enermy_count].x = x;
// 	game->enermies[game->enermy_count].y = y;
// 	game->enermy_count++;
// 	mlx_put_image_to_window(game->mlx, game->win, game->enermy,
// 		x * XPM_WIDTH, y * XPM_HEIGHT);
// }

static void	image_to_it(t_data *game, int y, int x)
{
	if (game->map[y][x] == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			x * XPM_WIDTH, y * XPM_HEIGHT);
	else if (game->map[y][x] == COLLECT)
		mlx_put_image_to_window(game->mlx, game->win, game->collect,
			x * XPM_WIDTH, y * XPM_HEIGHT);
	else if (game->map[y][x] == PLAYER)
		position_player(game, x, y);
	else if (game->map[y][x] == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			x * XPM_WIDTH, y * XPM_HEIGHT);
	else if (game->map[y][x] == FLOOR)
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			x * XPM_WIDTH, y * XPM_HEIGHT);
	else if (game->map[y][x] == ENERMY)
		mlx_put_image_to_window(game->mlx, game->win, game->,
			x * XPM_WIDTH, y * XPM_HEIGHT);
}

int	put_to_win(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			image_to_it(game, y, x);
		}
	}
	return (0);
}
