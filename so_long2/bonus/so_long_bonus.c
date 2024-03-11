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

#include "so_long_bonus.h"

int	check_input(char *av)
{
	int	i;

	i = strlen(av) - 4;
	if (strncmp(&av[i], ".ber", 4) == 0)
		return (1);
	return (0);
}

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
 * 1. set all the struct to NULL and 0
 * 2. read the .ber and assign to map
 * 3. check if the map is valid & check if the input is valid
 * 4. if all is valid, initialize the game
 * 5. start the game
 * 6. loop the game
 * 7. if the map is not valid, free the map and print error
 */
int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	ft_bzero(&game, sizeof(t_data));
	game.map = read_map(av[1]);
	if (!game.map || !check_map(&game) || !check_input(av[1]))
	{
		if (game.map != NULL)
			free_all(game.map);
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	init(&game);
	gameplay(&game);
	mlx_loop(game.mlx);
}
