/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:49:01 by welow             #+#    #+#             */
/*   Updated: 2024/02/07 20:49:01 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	free_all(t_data *game)
{
	int	i;

	i = 0;
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	while (i < game->heightmap - 1)
		free(game->map[i++]);
	free(game->map);
	exit(EXIT_SUCCESS);
}
