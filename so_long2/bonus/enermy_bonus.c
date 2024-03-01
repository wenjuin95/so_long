/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enermy_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:14:08 by welow             #+#    #+#             */
/*   Updated: 2024/03/01 17:13:21 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enermy_follow_up(t_data *game)
{
	if (game->y_axis + 2 < game->map_height
		&& game->map[game->y_axis + 2][game->x_axis] == ENERMY)
	{
		game->map[game->y_axis + 2][game->x_axis] = FLOOR;
		game->map[game->y_axis + 1][game->x_axis] = ENERMY;
	}
}

void	enermy_follow_down(t_data *game)
{
	if (game->y_axis - 2 >= 0
		&& game->map[game->y_axis - 2][game->x_axis] == ENERMY)
	{
		game->map[game->y_axis - 2][game->x_axis] = FLOOR;
		game->map[game->y_axis - 1][game->x_axis] = ENERMY;
	}
}

void	enermy_follow_left(t_data *game)
{
	if (game->x_axis + 2 < game->map_width
		&& game->map[game->y_axis][game->x_axis + 2] == ENERMY)
	{
		game->map[game->y_axis][game->x_axis + 2] = FLOOR;
		game->map[game->y_axis][game->x_axis + 1] = ENERMY;
	}
}

void	enermy_follow_right(t_data *game)
{
	if (game->x_axis - 2 >= 0
		&& game->map[game->y_axis][game->x_axis - 2] == ENERMY)
	{
		game->map[game->y_axis][game->x_axis - 2] = FLOOR;
		game->map[game->y_axis][game->x_axis - 1] = ENERMY;
	}
}
