/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:31:13 by welow             #+#    #+#             */
/*   Updated: 2024/02/14 17:31:13 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_image(t_data *game)
{
	if (game->item_pos == 0)
		game->collect = mlx_xpm_file_to_image(game->mlx,
				IMG_I, &game->image_w, &game->image_h);
	else if (game->item_pos == 1)
		game->collect = mlx_xpm_file_to_image(game->mlx,
				IMG_I2, &game->image_w, &game->image_h);
	else if (game->item_pos == 2)
		game->collect = mlx_xpm_file_to_image(game->mlx,
				IMG_I3, &game->image_w, &game->image_h);
	else if (game->item_pos == 3)
		game->collect = mlx_xpm_file_to_image(game->mlx,
				IMG_I4, &game->image_w, &game->image_h);
	else if (game->item_pos == 4)
	{
		game->collect = mlx_xpm_file_to_image(game->mlx,
				IMG_I5, &game->image_w, &game->image_h);
		game->item_pos = -1;
	}
}

int	animation(t_data *game)
{
	if (game->loop < 10000)
	{
		game->loop++;
		return (0);
	}
	game->loop = 0;
	mlx_destroy_image(game->mlx, game->collect);
	load_image(game);
	put_to_win(game);
	game->item_pos++;
	return (0);
}
