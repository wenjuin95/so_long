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

#include "so_long_bonus.h"

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

/*
 * 1. increase the frame if is not equal 1000
 * 2. equal 1000 only chg image
 */
int	animation(t_data *game)
{
	game->frame++;
	if (game->frame == 1000)
	{
		mlx_destroy_image(game->mlx, game->collect);
		load_image(game);
		put_to_win(game);
		game->item_pos++;
		game->frame = 0;
	}
	return (0);
}
