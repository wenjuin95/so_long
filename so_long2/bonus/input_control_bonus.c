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

#include "so_long_bonus.h"

int	free_game(t_data *game)
{
	free_all(game->map);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->enermy);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

void	input_control(t_data *game)
{
	mlx_hook(game->win, 2, 0, control, game);
	mlx_key_hook(game->win, enermy_control, game);
	mlx_hook(game->win, 17, 0, free_game, game);
	mlx_loop_hook(game->mlx, animation, game);
}
