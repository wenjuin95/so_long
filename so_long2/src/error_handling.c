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

#include "so_long.h"

//check each row it is similar to the first row
int	check_rec(char **map)
{
	int	i;

	if (*map == NULL)
		return (0);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

/*
*	1. check the column wall
*	2. check the row wall
*/
int	check_wall(char **map)
{
	int	h;
	int	w;
	int	len;

	if (*map == NULL)
		return (0);
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
	h = 0;
	len = ft_strlen(map[h]);
	while (map[h])
	{
		if (map[h][0] != '1' || map[h][len - 1] != '1')
			return (0);
		h++;
	}
	return (1);
}

void	check_if_pec(t_data *game, int h, int w)
{
	if (game->map[h][w] == 'P')
	{
		game->x_axis = w;
		game->y_axis = h;
		game->p_count++;
	}
	if (game->map[h][w] == 'E')
		game->e_count++;
	if (game->map[h][w] == 'C')
		game->c_count++;
}

/*
*	1. (extend)check if the map has only player, exit and collectible
*/
int	check_pec(t_data *game)
{
	int	h;
	int	w;

	h = 0;
	while (game->map[h])
	{
		w = 0;
		while (game->map[h][w])
		{
			check_if_pec(game, h, w);
			w++;
		}
		h++;
	}
	if (game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
		return (0);
	return (1);
}

//check any other character in this map
int	valid_map(t_data *game)
{
	int	h;
	int	w;

	h = 0;
	while (game->map[h])
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] != '1' && game->map[h][w] != '0'
				&& game->map[h][w] != 'P' && game->map[h][w] != 'E'
				&& game->map[h][w] != 'C')
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}
