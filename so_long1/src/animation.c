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
				IMG_I, &width, &height);
	else if (game->item_pos == 1)
		game->item = mlx_xpm_file_to_image(game->mlx,
				IMG_I2, &width, &height);
	else if (game->item_pos == 2)
		game->item = mlx_xpm_file_to_image(game->mlx,
				IMG_I3, &width, &height);
	else if (game->item_pos == 3)
		game->item = mlx_xpm_file_to_image(game->mlx,
				IMG_I4, &width, &height);
	else if (game->item_pos == 4)
	{
		game->item = mlx_xpm_file_to_image(game->mlx,
				IMG_I5, &width, &height);
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
