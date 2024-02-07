/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:09:37 by welow             #+#    #+#             */
/*   Updated: 2024/02/07 20:09:37 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_data *game)
{
	int	width;
	int	height;

	if (game->item_pos == 0)
		game->item = mlx_xpm_file_to_image(game->mlx,
				"asset/item.xpm", &width, &height);
	else if (game->item_pos == 1)
		game->item = mlx_xpm_file_to_image(game->mlx,
				"asset/item2.xpm", &width, &height);
	else if (game->item_pos == 2)
		game->item = mlx_xpm_file_to_image(game->mlx,
				"asset/item3.xpm", &width, &height);
	else if (game->item_pos == 3)
		game->item = mlx_xpm_file_to_image(game->mlx,
				"asset/item4.xpm", &width, &height);
	else if (game->item_pos == 4)
	{
		game->item = mlx_xpm_file_to_image(game->mlx,
				"asset/item5.xpm", &width, &height);
		game->item_pos = -1;
	}
}

int	animation(t_data *game)
{
	if (game->fps < 2000)
	{
		game->fps++;
		return (0);
	}
	game->fps = 0;
	mlx_destroy_image(game->mlx, game->item);
	load_image(game);
	put_to_win(game);
	game->item_pos++;
	return (0);
}
