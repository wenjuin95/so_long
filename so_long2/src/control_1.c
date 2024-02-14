/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:24:58 by welow             #+#    #+#             */
/*   Updated: 2024/02/13 23:24:58 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_step(t_data *game)
{
	game->step++;
	ft_printf("Step: %d\n", game->step);
}

void	free_enermy(t_data *game)
{
	ft_printf("\nYOU LOSE\n\n");
	free_game(game);
}

void	change_exit(t_data *game, int x, int y)
{
	mlx_destroy_image(game->mlx, game->exit);
	game->exit = mlx_xpm_file_to_image(game->mlx, IMG_E2,
			&game->image_w, &game->image_h);
	mlx_put_image_to_window(game->mlx, game->win, game->exit,
		x * XPM_WIDTH, y * XPM_HEIGHT);
}

static void	game_key(int keycode, t_data *game)
{
	if (keycode == W)
	{
		game->y_axis--;
		move_up(game, keycode);
	}
	else if (keycode == S)
	{
		game->y_axis++;
		move_down(game, keycode);
	}
	else if (keycode == A)
	{
		game->x_axis--;
		move_left(game, keycode);
	}
	else if (keycode == D)
	{
		game->x_axis++;
		move_right(game, keycode);
	}
}

int	control(int keycode, t_data *game)
{
	if (keycode == ESC || keycode == Q)
		free_game(game);
	else if (!game->play)
		game_key(keycode, game);
	return (0);
}
