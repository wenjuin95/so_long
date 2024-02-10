/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:21:10 by welow             #+#    #+#             */
/*   Updated: 2024/02/09 21:21:10 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_for_key(t_data *game, int keycode)
{
	int	height;
	int	width;

	mlx_destroy_image(game->mlx, game->player);
	if (keycode == W)
		game->player = mlx_xpm_file_to_image(game->mlx,
				IMG_P_UP, &width, &height);
	if (keycode == S)
		game->player = mlx_xpm_file_to_image(game->mlx,
				IMG_P, &width, &height);
	if (keycode == D)
		game->player = mlx_xpm_file_to_image(game->mlx,
				IMG_P_RIGHT, &width, &height);
	if (keycode == A)
		game->player = mlx_xpm_file_to_image(game->mlx,
				IMG_P_LEFT, &width, &height);
}

int	check_move(t_data *game, int x, int y)
{
	if (game->map[y][x] == EXIT)
	{
		if (game->items != 0)
			return (0);
		ft_printf("\nYOU WIN!!\n");
		free_all(game);
	}
	if (game->map[y][x] == FLOOR)
	{
		game->map[y][x] = PLAYER;
		game->x_axis = x;
		game->y_axis = y;
		game->step++;
	}
	if (game->map[y][x] == ITEM)
	{
		game->map[y][x] = PLAYER;
		game->x_axis = x;
		game->y_axis = y;
		game->step++;
		game->items--;
	}
	if (game->map[y][x] == ENERMY)
	{
		ft_printf("\nYou had lost the game\n\n");
		free_all(game);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	control(int keycode, t_data *game)
{
	int	executable;

	if (keycode == ESC || keycode == Q)
	{
		ft_printf("\nYou had quit the game\n\n");
		free_all(game);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W)
		executable = move_up(game, keycode);
	if (keycode == S)
		executable = move_down(game, keycode);
	if (keycode == A)
		executable = move_left(game, keycode);
	if (keycode == D)
		executable = move_right(game, keycode);
	if (executable == 0)
		put_to_win(game);
	return (1);
}

