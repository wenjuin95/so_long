/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:29:24 by welow             #+#    #+#             */
/*   Updated: 2024/02/06 20:29:24 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_outer_rectangle(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if (i == 0 || i == game->heightmap - 1 || j == 0
				|| j == game->widthmap - 1)
			{
				if (game->map[i][j] != '1')
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static void	check(t_data *game, int height, int width)
{
	if (game->map[height][width] == 'P')
		game->player_count++;
	if (game->map[height][width] == 'C')
		game->item_count++;
	if (game->map[height][width] == 'E')
		game->exit_count++;
}

void	check_p_e_c(t_data *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			check(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->player_count == 1 && game->item_count > 1
			&& game->exit_count == 1))
	{
		ft_printf("\nERROR\n");
		ft_printf("player? exit? item? file exist?\n\n");
		free_all(game);
	}
}

void	check_wall(t_data *game)
{
	if (check_outer_rectangle(game) == false)
	{
		ft_printf("ERROR\n");
		ft_printf("Map is not surrounded by walls\n");
		free_all(game);
	}
}
