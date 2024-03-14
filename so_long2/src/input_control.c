/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 23:05:18 by welow             #+#    #+#             */
/*   Updated: 2024/02/13 23:05:18 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	1.free all the memory that has been allocated and exit the program
*/
int	free_game(t_data *game)
{
	free_all(game->map);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

/*
*	1. control is to control the player
* 	2. free_game is to free the game (when you press the red cross)
*/
void	input_control(t_data *game)
{
	mlx_hook(game->win, 2, (1L << 0), control, game);
	mlx_hook(game->win, 17, 0, free_game, game);
}
