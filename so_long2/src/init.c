/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:44:25 by welow             #+#    #+#             */
/*   Updated: 2024/02/13 21:44:25 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
*	get_window_size is to get the size of the window
*/
static void	get_window_size(t_data *game)
{
	int	i;

	game->map_width = ft_strlen(game->map[0]) * XPM_WIDTH;
	i = 0;
	while (game->map[i])
		i++;
	game->map_height = i * XPM_HEIGHT;
}

/*
*	1.the purpose of flood fill is to find the exit
* 	2.player will go trough the whole map and change the floor 
*	  and collect to 7 and 8
*	3.the purpose of chg 7 and 8 is to prevent the player from going back 
*	  to the floor and collect
*/
int	flood_fill(t_data *game, int x, int y)
{
	int	result;

	result = 0;
	if (x < 0 || y < 0 || game->map_width <= x || game->map_height <= y)
		return (0);
	if (game->map[y][x] == '1' || game->map[y][x] == '7'
		|| game->map[y][x] == '8')
		return (0);
	if (game->map[y][x] == 'P')
		;
	if (game->map[y][x] == 'C')
		game->map[y][x] = '7';
	if (game->map[y][x] == '0')
		game->map[y][x] = '8';
	if (game->map[y][x] == 'E')
		return (1);
	result |= flood_fill(game, x + 1, y);
	result |= flood_fill(game, x - 1, y);
	result |= flood_fill(game, x, y + 1);
	result |= flood_fill(game, x, y - 1);
	return (result);
}

void	check_exit(t_data *game)
{
	if (flood_fill(game, game->x_axis, game->y_axis) == 0)
	{
		ft_printf("Error: not found exit\n");
		free_all(game->map);
		exit(EXIT_FAILURE);
	}
}

/*
*	1.get the size map
*	2.check the did found exit
*	3.put image 
* 
*/
void	init(t_data *game)
{
	game->mlx = mlx_init();
	get_window_size(game);
	game->win = mlx_new_window(game->mlx, game->map_width, game->map_height,
			"so_long");
	check_exit(game);
	place_xpm_to_image(game);
	put_to_win(game);
}
