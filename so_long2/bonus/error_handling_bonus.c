/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:07:41 by welow             #+#    #+#             */
/*   Updated: 2024/02/13 21:07:41 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	check_input(char *av)
{
	int	i;

	i = strlen(av) - 4;
	if (strncmp(&av[i], ".ber", 4) == 0)
		return (1);
	return (0);
}

static int	check_wall(char **map)
{
	int	h;
	int	w;
	int	len;

	h = 0;
	w = 0;
	while (map[h])
		h++;
	while (map[0][w] && map[h - 1][w])
	{
		if (map[0][w] != '1' || map[h - 1][w] != '1')
			return (0);
		w++;
	}
	h = 1;
	len = ft_strlen(map[h]);
	while (map[h])
	{
		if (map[h][0] != '1' || map[h][len - 1] != '1')
			return (0);
		h++;
	}
	return (1);
}

static int	check_pec(t_data *game)
{
	int	h;
	int	w;

	h = 0;
	while (game->map[h])
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == 'P')
				game->p_count++;
			if (game->map[h][w] == 'E')
				game->e_count++;
			if (game->map[h][w] == 'C')
				game->c_count++;
			w++;
		}
		h++;
	}
	if (game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
		return (0);
	return (1);
}

int	check_map(t_data *game)
{
	if (check_wall(game->map) != 0 && check_pec(game) != 0)
		return (1);
	return (0);
}
