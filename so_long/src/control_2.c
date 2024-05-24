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

#include "so_long.h"

int	move_up(t_data *game, int keycode)
{
	int	i;
	int	y;
	int	x;

	y = game->y_axis;
	x = game->x_axis;
	image_for_key(game, keycode);
	if (keycode == W)
	{
		y--;
		if (game->map[y][x] == WALL)
			return (0);
		i = check_move(game, x, y);
		if (i == 0)
			return (0);
		game->map[y + 1][x] = FLOOR;
	}
	ft_printf("Step taken: %d\n", game->step);
	ft_printf("Items left: %d\n\n", game->c_count);
	return (1);
}

int	move_down(t_data *game, int keycode)
{
	int	i;
	int	y;
	int	x;

	y = game->y_axis;
	x = game->x_axis;
	image_for_key(game, keycode);
	if (keycode == S)
	{
		y++;
		if (game->map[y][x] == WALL)
			return (0);
		i = check_move(game, x, y);
		if (i == 0)
			return (0);
		game->map[y - 1][x] = FLOOR;
	}
	ft_printf("Step taken: %d\n", game->step);
	ft_printf("Items left: %d\n\n", game->c_count);
	return (1);
}

int	move_left(t_data *game, int keycode)
{
	int	i;
	int	y;
	int	x;

	y = game->y_axis;
	x = game->x_axis;
	image_for_key(game, keycode);
	if (keycode == A)
	{
		x--;
		if (game->map[y][x] == WALL)
			return (0);
		i = check_move(game, x, y);
		if (i == 0)
			return (0);
		game->map[y][x + 1] = FLOOR;
	}
	ft_printf("Step taken: %d\n", game->step);
	ft_printf("Items left: %d\n\n", game->c_count);
	return (1);
}

int	move_right(t_data *game, int keycode)
{
	int	i;
	int	y;
	int	x;

	y = game->y_axis;
	x = game->x_axis;
	image_for_key(game, keycode);
	if (keycode == D)
	{
		x++;
		if (game->map[y][x] == WALL)
			return (0);
		i = check_move(game, x, y);
		if (i == 0)
			return (0);
		game->map[y][x - 1] = FLOOR;
	}
	ft_printf("Step taken: %d\n", game->step);
	ft_printf("Items left: %d\n\n", game->c_count);
	return (1);
}
