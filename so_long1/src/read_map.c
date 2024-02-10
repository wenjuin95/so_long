/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:21:45 by welow             #+#    #+#             */
/*   Updated: 2024/02/06 20:21:45 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		{
			free(read);
			break ;
		}
	}
	close(game->fd);
	game->widthmap = get_width_lenght(game->map[0]);
	return (1);
}
