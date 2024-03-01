/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:32:52 by welow             #+#    #+#             */
/*   Updated: 2024/02/13 23:32:52 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	move_up(t_data *game, int keycode)
{
	image_for_key(game, keycode);
	if (game->map[game->y_axis][game->x_axis] == EXIT && game->c_count == 0)
	{
		ft_printf("\nYOU WIN!!\n\n");
		free_game(game);
	}
	else if (game->map[game->y_axis][game->x_axis] == ENERMY)
		free_enermy(game);
	else if (game->map[game->y_axis][game->x_axis] == WALL ||
			game->map[game->y_axis][game->x_axis] == EXIT)
		game->y_axis += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_axis][game->x_axis] == COLLECT)
		{
			game->c_count--;
			if (game->c_count == 0)
				change_exit(game, game->x_axis, game->y_axis);
		}
		game->map[game->y_axis][game->x_axis] = PLAYER;
		game->map[game->y_axis + 1][game->x_axis] = FLOOR;
		print_step(game);
	}
}

void	move_down(t_data *game, int keycode)
{
	image_for_key(game, keycode);
	if (game->map[game->y_axis][game->x_axis] == EXIT && game->c_count == 0)
	{
		ft_printf("\nYOU WIN!!\n\n");
		free_game(game);
	}
	else if (game->map[game->y_axis][game->x_axis] == ENERMY)
		free_enermy(game);
	else if (game->map[game->y_axis][game->x_axis] == WALL ||
			game->map[game->y_axis][game->x_axis] == EXIT)
		game->y_axis -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_axis][game->x_axis] == COLLECT)
		{
			game->c_count--;
			if (game->c_count == 0)
				change_exit(game, game->x_axis, game->y_axis);
		}
		game->map[game->y_axis][game->x_axis] = PLAYER;
		game->map[game->y_axis - 1][game->x_axis] = FLOOR;
		print_step(game);
	}
}

void	move_left(t_data *game, int keycode)
{
	image_for_key(game, keycode);
	if (game->map[game->y_axis][game->x_axis] == EXIT && game->c_count == 0)
	{
		ft_printf("\nYOU WIN!!\n\n");
		free_game(game);
	}
	else if (game->map[game->y_axis][game->x_axis] == ENERMY)
		free_enermy(game);
	else if (game->map[game->y_axis][game->x_axis] == WALL ||
			game->map[game->y_axis][game->x_axis] == EXIT)
		game->x_axis += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_axis][game->x_axis] == COLLECT)
		{
			game->c_count--;
			if (game->c_count == 0)
				change_exit(game, game->x_axis, game->y_axis);
		}
		game->map[game->y_axis][game->x_axis] = PLAYER;
		game->map[game->y_axis][game->x_axis + 1] = FLOOR;
		print_step(game);
	}
}

void	move_right(t_data *game, int keycode)
{
	image_for_key(game, keycode);
	if (game->map[game->y_axis][game->x_axis] == EXIT && game->c_count == 0)
	{
		ft_printf("\nYOU WIN!!\n\n");
		free_game(game);
	}
	else if (game->map[game->y_axis][game->x_axis] == ENERMY)
		free_enermy(game);
	else if (game->map[game->y_axis][game->x_axis] == WALL ||
			game->map[game->y_axis][game->x_axis] == EXIT)
		game->x_axis -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_axis][game->x_axis] == COLLECT)
		{
			game->c_count--;
			if (game->c_count == 0)
				change_exit(game, game->x_axis, game->y_axis);
		}
		game->map[game->y_axis][game->x_axis] = PLAYER;
		game->map[game->y_axis][game->x_axis - 1] = FLOOR;
		print_step(game);
	}
}
