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
1000 threshold value used to determine when the animation loop should perform certain actions.

In this context, it seems to be controlling the duration of each frame of the animation. 
When game->frame reaches 1000, performs actions such as destroying the previous image, 
loading a new image, and updating the position of an item in the game window.
then resets game->frame to 0 for the next frame.

1000 acts as a limit for the number of frames before certain actions are taken to update the animation state. 
Once this limit is reached, the animation "resets" and starts over from the beginning. 
djusting this value can control the speed or duration of the animation.
*/
// int	animation(t_data *game)
// {
// 	if (game->frame <= 1000)
// 	{
// 		game->frame++;
// 		return (0);
// 	}
// 	mlx_destroy_image(game->mlx, game->collect);
// 	load_image(game);
// 	put_to_win(game);
// 	game->item_pos++;
// 	game->frame = 0;
// 	return (0);
// }

/*
 * 1. increase the frame if is not equal 1000
 * 2. equal 3000 only chg image
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

