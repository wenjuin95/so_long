/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:52:53 by welow             #+#    #+#             */
/*   Updated: 2024/02/13 20:52:53 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check if the input is a .ber file
void	check_input(char *av)
{
	int	i;

	i = ft_strlen(av) - 4;
	if (ft_strncmp(&av[i], ".ber", 4) != 0)
	{
		ft_printf("not a .ber\n");
		exit(EXIT_FAILURE);
	}
}

// only free memory
void	free_all(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/*
* 1. game.map if is something in it, we also need to check the map
* 2. if the map is not valid with another condition (game->map != NULL)
	 , we free the memory and exit
*/
int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	ft_bzero(&game, sizeof(t_data));
	check_input(av[1]);
	game.map = read_map(av[1]);
	if (!game.map || !check_map(&game))
	{
		if (game.map != NULL)
			free_all(game.map);
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	input_image(&game);
	input_control(&game);
	mlx_loop(game.mlx);
}
