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
	mlx_destroy_image(game->mlx, game->item);
	load_image(game);
	game->item_pos++;
	usleep(100000);
	put_to_win(game);
	return (0);
}

// int animation(t_data *game) {
//     static int frame_counter = 0; // Static variable to count frames

//     // Increment frame counter
//     frame_counter++;

//     // Check if 0.1 second has passed (10 frames at 10 fps)
//     if (frame_counter == 2000) {
//         // Reset frame counter
//         frame_counter = 0;
        
//         // Destroy the currently displayed image
//         mlx_destroy_image(game->mlx, game->item);
        
//         // Load the next image and update item_pos
//         load_image(game);
//         game->item_pos++;
        
//         // Update the window display
//         put_to_win(game);
//     }
    
//     // Sleep for 0.1 second (100,000 microseconds) to achieve desired frame rate
//     // usleep(100000);

//     return 0; // Return 0 indicating successful completion
// }




