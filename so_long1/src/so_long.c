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

#include "../src/so_long.h"
#include <stdio.h>

int	exit_point(t_data *game)
{
	int	line;

	line = 0;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

static int	horizontalwall(t_data *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->heightmap - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

static int	verticalwall(t_data *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1' && game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	if_walls(t_data *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("\nThis map is missing the walls\n");
		exit_point(game);
	}
}

static void	count_checker(t_data *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("\nError Here!%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
			game->column_count++;
	if (game->map[height][width] == 'P')
			game->player_count++;
	if (game->map[height][width] == 'E')
			game->exit_count++;
}

void	character_valid(t_data *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->map[height][width])
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->player_count == 1 && game->column_count > 1
			&& game->exit_count == 1))
	{
		printf("\nError\nSomething is wrong!\n");
		printf("either player, exit or collectable issue\n");
		exit_point(game);
	}
}

void	check_errors(t_data *game)
{
	if_walls(game);
	character_valid(game);
}

void	position_player(t_data *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player,
		width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	position_item(t_data *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx, game->win, game->item, width * 40, height * 40);
	game->items++;
}

void	adding_in_win(t_data *game)
{
	int	height;
	int	width;

	game->items = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, width * 40, height * 40);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, width * 40, height * 40);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, width * 40, height * 40);
			if (game->map[height][width] == 'P')
				position_player(game, height, width);
			if (game->map[height][width] == 'C')
				position_item(game, height, width);
			width++;
		}
		height++;
	}
}

void	place_image_in_game(t_data *game)
{
	int	x;
	int	y;

	game->floor = mlx_xpm_file_to_image(game->mlx, "asset/floor.xpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "asset/wall.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, "asset/player_down.xpm", &x, &y);
	game->item = mlx_xpm_file_to_image(game->mlx, "asset/item.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "asset/exit.xpm", &x, &y);
}

static int	width_of_map(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == '\n')
		i--;
	return (i);
}

static int	add_line(t_data *game, char *line)
{
	char	**temp;
	int		i;
	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temp = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temp[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}


int	read_map(t_data *game, char **av)
{
	char	*readmap;
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (add_line(game, readmap) == 0)
			break;
		
	}
	close(game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_data));
	read_map(&game,	av);
	check_errors(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (game.widthmap * 40), (game.heightmap * 40), "so_long");
	place_image_in_game(&game);
	adding_in_win(&game);
	mlx_loop(game.mlx);
}