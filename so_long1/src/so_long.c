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

int	main(int ac, char **av)
{
	t_data	game;

	check_input(ac, av);
	ft_bzero(&game, sizeof(t_data));
	read_map_content(&game, av);
	check_p_e_c(&game);
	check_wall(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			XPM_WIDTH * game.widthmap, XPM_HEIGHT * game.heightmap, "so_long");
	place_xpm_to_image(&game);
	put_to_win(&game);
	//02: keypress, (1L << 0): keypressmask
	mlx_hook(game.win, 02, 1L << 0, control, &game);
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_loop(game.mlx);
}
