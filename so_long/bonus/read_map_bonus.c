/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:36:36 by welow             #+#    #+#             */
/*   Updated: 2024/02/13 21:36:36 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**read_map(char *av)
{
	int		fd;
	char	*read;
	char	*tmp_map;
	char	*tmp;
	char	**map;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp_map = ft_strdup("");
	while (1)
	{
		read = get_next_line(fd);
		if (!read)
			break ;
		tmp = tmp_map;
		tmp_map = ft_strjoin(tmp, read);
		free(read);
		free(tmp);
	}
	map = ft_split(tmp_map, '\n');
	free(tmp_map);
	close(fd);
	return (map);
}
