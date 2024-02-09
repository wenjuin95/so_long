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

void	place_xpm_to_image(t_data *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx, IMG_F,
			&width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, IMG_W,
			&width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx, IMG_P,
			&width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, IMG_E,
			&width, &height);
	game->item = mlx_xpm_file_to_image(game->mlx, IMG_I,
			&width, &height);
}

static void	position_item(t_data *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win, game->item,
		width * XPM_WIDTH, height * XPM_HEIGHT);
	game->items++;
}

static void	position_player(t_data *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player,
		width * XPM_WIDTH, height * XPM_HEIGHT);
	game->y_axis = height;
	game->x_axis = width;
}

static void	image_to_it(t_data *game, int height, int width)
{
	if (game->map[height][width] == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			width * XPM_WIDTH, height * XPM_HEIGHT);
	if (game->map[height][width] == ITEM)
		position_item(game, width, height);
	if (game->map[height][width] == PLAYER)
		position_player(game, width, height);
	if (game->map[height][width] == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			width * XPM_WIDTH, height * XPM_HEIGHT);
	if (game->map[height][width] == FLOOR)
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			width * XPM_WIDTH, height * XPM_HEIGHT);
}

void	put_to_win(t_data *game)
{
	int	height;
	int	width;

	game->items = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (width < game->widthmap)
		{
			image_to_it(game, height, width);
			width++;
		}
		height++;
	}
}
