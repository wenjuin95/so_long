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

int	control(int keycode, t_data *game)
{
	if (keycode == ESC || keycode == Q)
	{
		ft_printf("\nYou had quit the game\n\n");
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		exit(1);
	}
	return (0);
}

bool	check_format(char *av)
{
	int	i;

	i = strlen(av) - 4;
	if (strncmp(&av[i], ".ber", 4) == 0)
		return (true);
	return (false);
}

void	check_input(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("\nERROR\n");
		ft_printf("INPUT: ./so_long map/<choose map>.ber\n\n");
		exit(EXIT_FAILURE);
	}
	if (ac == 2 && !check_format(av[1]))
	{
		ft_printf("\nERROR\n");
		ft_printf("INPUT: ./so_long map/<choose map>.ber\n\n");
		exit(EXIT_FAILURE);
	}
}

int free_all(t_data *game)
{
	int i;

	i = 0;
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	while (i < game->heightmap - 1)
		free(game->map[i++]);
	free(game->map);
	exit(0);
}


int	main(int ac, char **av)
{
	t_data	game;

	check_input(ac, av);
	ft_bzero(&game, sizeof(t_data));
	read_map_content(&game, av);
	check_P_E_C(&game);
	check_wall(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			XPM_WIDTH * game.widthmap, XPM_HEIGHT * game.heightmap, "so_long");
	place_xpm_to_image(&game);
	put_to_win(&game);
	mlx_key_hook(game.win, control, &game);
	mlx_loop(game.mlx);
}


