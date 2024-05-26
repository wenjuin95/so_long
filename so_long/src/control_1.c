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

/*
*	1.chg position player
*/
void	image_for_key(t_data *game, int keycode)
{
	mlx_destroy_image(game->mlx, game->player);
	if (keycode == W)
		game->player = mlx_xpm_file_to_image(game->mlx,
				IMG_P_UP, &game->image_w, &game->image_h);
	if (keycode == S)
		game->player = mlx_xpm_file_to_image(game->mlx,
				IMG_P, &game->image_w, &game->image_h);
	if (keycode == D)
		game->player = mlx_xpm_file_to_image(game->mlx,
				IMG_P_RIGHT, &game->image_w, &game->image_h);
	if (keycode == A)
		game->player = mlx_xpm_file_to_image(game->mlx,
				IMG_P_LEFT, &game->image_w, &game->image_h);
}

/*
*	1.(extend)check item
*/
static void	check_item(t_data *game, int x, int y)
{
	if (game->map[y][x] == COLLECT)
	{
		game->map[y][x] = PLAYER;
		game->x_axis = x;
		game->y_axis = y;
		game->step++;
		game->c_count--;
		if (game->c_count == 0)
		{
			mlx_destroy_image(game->mlx, game->exit);
			game->exit = mlx_xpm_file_to_image(game->mlx,
					IMG_E2, &game->image_w, &game->image_h);
		}
	}
}

/*
*	1.check move
*/
int	check_move(t_data *game, int x, int y)
{
	check_item(game, x, y);
	if (game->map[y][x] == EXIT)
	{
		if (game->c_count != 0)
			return (0);
		ft_printf("\nYOU WIN!!\n\n");
		free_game(game);
	}
	if (game->map[y][x] == FLOOR)
	{
		game->map[y][x] = PLAYER;
		game->x_axis = x;
		game->y_axis = y;
		game->step++;
	}
	return (1);
}

/*
*	note: the excutable is to check if the move is executable
*/
int	control(int keycode, t_data *game)
{
	if (keycode == ESC || keycode == Q)
	{
		ft_printf("\nYou had quit the game\n\n");
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W)
		move_up(game, keycode);
	if (keycode == S)
		move_down(game, keycode);
	if (keycode == A)
		move_left(game, keycode);
	if (keycode == D)
		move_right(game, keycode);
	put_to_win(game);
	return (1);
}
