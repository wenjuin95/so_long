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

#include "so_long_bonus.h"

static void	display_string(t_data *game)
{
	char	*step;
	char	*item;

	step = ft_itoa(game->step);
	item = ft_itoa(game->c_count);
	mlx_string_put(game->mlx, game->win, 5, 15, 0xFFFFFF, "Step:");
	mlx_string_put(game->mlx, game->win, 40, 15, 0xFFFFFF, step);
	mlx_string_put(game->mlx, game->win, 5, 25, 0xFFFFFF, "item:");
	mlx_string_put(game->mlx, game->win, 40, 25, 0xFFFFFF, item);
	free(step);
	free(item);
}

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

static void	image_to_it(t_data *game, int y, int x)
{
	if (game->map[y][x] == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			x * XPM_WIDTH, y * XPM_HEIGHT);
	else if (game->map[y][x] == COLLECT)
		mlx_put_image_to_window(game->mlx, game->win, game->collect,
			x * XPM_WIDTH, y * XPM_HEIGHT);
	else if (game->map[y][x] == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			x * XPM_WIDTH, y * XPM_HEIGHT);
	else if (game->map[y][x] == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			x * XPM_WIDTH, y * XPM_HEIGHT);
	else if (game->map[y][x] == FLOOR)
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			x * XPM_WIDTH, y * XPM_HEIGHT);
	else if (game->map[y][x] == ENERMY)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->enermy,
			x * XPM_WIDTH, y * XPM_HEIGHT);
		game->x_enermy = x;
		game->y_enermy = y;
	}
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
	display_string(game);
	return (0);
}
