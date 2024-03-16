/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enermy_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:14:08 by welow             #+#    #+#             */
/*   Updated: 2024/03/16 23:12:03 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_player(t_data *game, int y, int x)
{
	if (game->map[y][x] == PLAYER)
	{
		ft_printf("\nYou have been caught by the enermy!\n\n");
		free_game(game);
	}
}

// static int	enermy_up(t_data *game, int keycode)
// {
// 	int	y;
// 	int	x;

// 	y = game->y_enermy;
// 	x = game->x_enermy;
// 	if (keycode == W)
// 	{
// 		y--;
// 		if (game->map[y][x] == WALL || game->map[y][x] == COLLECT
// 			|| game->map[y][x] == EXIT || game->map[y][x] == ENERMY)
// 			return (0);
// 		if (game->map[y][x] == PLAYER)
// 		{
// 			ft_printf("\nYou have been caught by the enermy!\n\n");
// 			free_game(game);
// 		}
// 		game->map[y + 1][x] = FLOOR;
// 		game->map[y][x] = ENERMY;
// 	}
// 	return (1);
// }

int	enermy_up(t_data *game, int keycode)
{
	int	y;
	int	x;

	y = game->y_enermy;
	x = game->x_enermy;
	if (keycode == W)
	{
		y--;
		if (game->map[y][x] == WALL || game->map[y][x] == EXIT
			|| game->map[y][x] == ENERMY)
			return (0);
		check_player(game, y, x);
		if (game->map[y][x] == COLLECT)
		{
			game->map[y + 1][x] = COLLECT;
			game->map[y][x] = ENERMY;
		}
		else
		{
			game->map[y + 1][x] = FLOOR;
			game->map[y][x] = ENERMY;
		}
	}
	return (1);
}

// static int	enermy_down(t_data *game, int keycode)
// {
// 	int	y;
// 	int	x;

// 	y = game->y_enermy;
// 	x = game->x_enermy;
// 	if (keycode == S)
// 	{
// 		y++;
// 		if (game->map[y][x] == WALL || game->map[y][x] == COLLECT
// 			|| game->map[y][x] == EXIT || game->map[y][x] == ENERMY)
// 			return (0);
// 		if (game->map[y][x] == PLAYER)
// 		{
// 			ft_printf("\nYou have been caught by the enermy!\n\n");
// 			free_game(game);
// 		}
// 		game->map[y - 1][x] = FLOOR;
// 		game->map[y][x] = ENERMY;
// 	}
// 	return (1);
// }

int	enermy_down(t_data *game, int keycode)
{
	int	y;
	int	x;

	y = game->y_enermy;
	x = game->x_enermy;
	if (keycode == S)
	{
		y++;
		if (game->map[y][x] == WALL || game->map[y][x] == EXIT
			|| game->map[y][x] == ENERMY)
			return (0);
		check_player(game, y, x);
		if (game->map[y][x] == COLLECT)
		{
			game->map[y - 1][x] = COLLECT;
			game->map[y][x] = ENERMY;
		}
		else
		{
			game->map[y - 1][x] = FLOOR;
			game->map[y][x] = ENERMY;
		}
	}
	return (1);
}

// static int	enermy_left(t_data *game, int keycode)
// {
// 	int	y;
// 	int	x;

// 	y = game->y_enermy;
// 	x = game->x_enermy;
// 	if (keycode == A)
// 	{
// 		x--;
// 		if (game->map[y][x] == WALL || game->map[y][x] == COLLECT
// 			|| game->map[y][x] == EXIT || game->map[y][x] == ENERMY)
// 			return (0);
// 		if (game->map[y][x] == PLAYER)
// 		{
// 			ft_printf("\nYou have been caught by the enermy!\n\n");
// 			free_game(game);
// 		}
// 		game->map[y][x + 1] = FLOOR;
// 		game->map[y][x] = ENERMY;
// 	}
// 	return (1);
// }

int	enermy_left(t_data *game, int keycode)
{
	int	y;
	int	x;

	y = game->y_enermy;
	x = game->x_enermy;
	if (keycode == A)
	{
		x--;
		if (game->map[y][x] == WALL || game->map[y][x] == EXIT
			|| game->map[y][x] == ENERMY)
			return (0);
		check_player(game, y, x);
		if (game->map[y][x] == COLLECT)
		{
			game->map[y][x + 1] = COLLECT;
			game->map[y][x] = ENERMY;
		}
		else
		{
			game->map[y][x + 1] = FLOOR;
			game->map[y][x] = ENERMY;
		}

	}
	return (1);
}

// static int	enermy_right(t_data *game, int keycode)
// {
// 	int	y;
// 	int	x;

// 	y = game->y_enermy;
// 	x = game->x_enermy;
// 	if (keycode == D)
// 	{
// 		x++;
// 		if (game->map[y][x] == WALL || game->map[y][x] == COLLECT
// 			|| game->map[y][x] == EXIT || game->map[y][x] == ENERMY)
// 			return (0);
// 		if (game->map[y][x] == PLAYER)
// 		{
// 			ft_printf("\nYou have been caught by the enermy!\n\n");
// 			free_game(game);
// 		}
// 		game->map[y][x - 1] = FLOOR;
// 		game->map[y][x] = ENERMY;
// 	}
// 	return (1);
// }

int	enermy_right(t_data *game, int keycode)
{
	int	y;
	int	x;

	y = game->y_enermy;
	x = game->x_enermy;
	if (keycode == D)
	{
		x++;
		if (game->map[y][x] == WALL || game->map[y][x] == EXIT
			|| game->map[y][x] == ENERMY)
			return (0);
		check_player(game, y, x);
		if (game->map[y][x] == COLLECT)
		{
			game->map[y][x - 1] = COLLECT;
			game->map[y][x] = ENERMY;
		}
		else
		{
			game->map[y][x - 1] = FLOOR;
			game->map[y][x] = ENERMY;
		}
	}
	return (1);
}


