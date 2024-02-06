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


void	place_xpm_to_image(t_data *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx, "asset/floor.xpm",
			&width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "asset/wall.xpm",
			&width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx, "asset/player_down.xpm",
			&width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "asset/exit.xpm",
			&width, &height);
	game->item = mlx_xpm_file_to_image(game->mlx, "asset/item.xpm",
			&width, &height);
}

void	position_item(t_data *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win, game->item,
		width * XPM_WIDTH, height * XPM_HEIGHT);
	game->items++;
}

void	position_player(t_data *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player,
		width * XPM_WIDTH, height * XPM_HEIGHT);
	game->y_axis = height;
	game->x_axis = width;
}

void	put_to_win(t_data *game)
{
	int	height;
	int	width;

	game->items = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (width < game->widthmap)
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall,
					width * XPM_WIDTH, height * XPM_HEIGHT);
			if (game->map[height][width] == 'C')
				position_item(game, width, height);
			if (game->map[height][width] == 'P')
				position_player(game, width, height);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit,
					width * XPM_WIDTH, height * XPM_HEIGHT);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor,
					width * XPM_WIDTH, height * XPM_HEIGHT);
			width++;
		}
		height++;
	}
}

int	get_width_lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	add_line(t_data *game, char *line)
{
	char	**tmp;
	int		i;

	if (line == NULL)
		return (0);
	i = 0;
	game->heightmap += 1;
	tmp = malloc(sizeof(char *) * (game->heightmap + 1));
	if (!tmp)
		return (0);
	tmp[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	free(game->map);
	game->map = tmp;
	return (1);
}

int	read_map_content(t_data *game, char **av)
{
	char	*read;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		read = get_next_line(game->fd);
		if (add_line(game, read) == 0)
			break ;
	}
	close(game->fd);
	game->widthmap = get_width_lenght(game->map[0]);
	return (1);
}

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