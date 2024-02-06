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

bool	check_format(char *av)
{
	int	i;

	i = strlen(av) - 4;
	if (strncmp(&av[i], ".ber", 4) == 0)
		return (true);
	return (false);
}

void	check_error(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Please input map for execute\n");
		exit(EXIT_FAILURE);
	}
	if (ac == 2 && !check_format(av[1]))
	{
		printf("invalid input\n");
		exit(EXIT_FAILURE);
	}
}