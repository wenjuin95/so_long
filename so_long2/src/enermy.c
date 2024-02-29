/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enermy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:14:08 by welow             #+#    #+#             */
/*   Updated: 2024/02/29 16:57:00 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_enermy(t_data *game)
{
	int	i;

	i = 0;
	if (game->enermy_pos == 0)
	{
		game->enermy = mlx_xpm_file_to_image(game->mlx,
				IMG_ENE, &game->image_w, &game->image_h);
		while (i < game->enermy_count)
		{
			if (game->map[game->enermies[i].x + 1][game->enermies[i].y] != WALL)
			{
				game->enermies[i].x++;
				game->map[game->enermies[i].x + 1][game->enermies[i].y] = ENERMY;
				game->map[game->enermies[i].x][game->enermies[i].y] = FLOOR;
			}
			else
			{
				game->enermies[i].x--;
				game->map[game->enermies[i].x - 1][game->enermies[i].y] = ENERMY;
				game->map[game->enermies[i].x][game->enermies[i].y] = FLOOR;
			}
			i++;
		}
	}
	else if (game->enermy_pos == 1)
	{
		game->enermy = mlx_xpm_file_to_image(game->mlx,
				IMG_ENE, &game->image_w, &game->image_h);
		while (i < game->enermy_count)
		{
			if (game->map[game->enermies[i].x - 1][game->enermies[i].y] != WALL)
			{
				game->enermies[i].x--;
				game->map[game->enermies[i].x - 1][game->enermies[i].y] = ENERMY;
				game->map[game->enermies[i].x][game->enermies[i].y] = FLOOR;
			}
			else
			{
				game->enermies[i].x++;
				game->map[game->enermies[i].x + 1][game->enermies[i].y] = ENERMY;
				game->map[game->enermies[i].x][game->enermies[i].y] = FLOOR;
			}
			i++;
		}
		game->enermy_pos = -1;
	}
}

int	enermy_move(t_data *game)
{
	if (game->frame < 1000)
	{
		game->frame++;
		return (0);
	}
	mlx_destroy_image(game->mlx, game->enermy);
	load_enermy(game);
	put_to_win(game);
	game->enermy_pos++;
	game->frame = 0;
	return (0);
}