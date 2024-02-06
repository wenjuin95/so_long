/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:44:58 by welow             #+#    #+#             */
/*   Updated: 2024/02/05 20:44:58 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_data));
	read_map_content(&game, av);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			XPM_WIDTH * game.widthmap, XPM_HEIGHT * game.heightmap, "so_long");
	place_xpm_to_image(&game);
	put_to_win(&game);
	mlx_loop(game.mlx);
}