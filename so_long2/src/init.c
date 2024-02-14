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

static void	get_window_size(t_data *game)
{
	int	i;

	game->map_width = ft_strlen(game->map[0]) * XPM_WIDTH;
	i = 0;
	while (game->map[i])
		i++;
	game->map_height = i * XPM_HEIGHT;
}

void	init(t_data *game)
{
	game->mlx = mlx_init();
	get_window_size(game);
	game->win = mlx_new_window(game->mlx, game->map_width, game->map_height,
			"so_long");
	place_xpm_to_image(game);
	put_to_win(game);
}
