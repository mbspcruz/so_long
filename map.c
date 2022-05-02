/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:21:19 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 19:46:25 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	number_of_lines(char *av)
{
	int		fd;
	int		rd;
	char	buff;
	int		line_count;

	rd = 1;
	fd = open(av, O_RDONLY);
	line_count = 1;
	while (rd == 1)
	{
		rd = read(fd, &buff, 1);
		if (buff == '\n')
			line_count++;
	}
	close(fd);
	if (line_count <= 0)
		error_message("Error\nThe file is empty");
	return (line_count);
}

char	**read_map(char *av, t_game data)
{
	int		fd;
	char	**map;
	int		i;
	int		len;

	i = 0;
	len = number_of_lines(av);
	map = malloc(sizeof (char *) * len + 1);
	if (map == NULL)
		return (NULL);
	fd = open(av, O_RDONLY);
	if (!fd || fd == -1)
		error_message("Error\nThe file might no exist");
	while (get_next_line(fd, &map[i++]))
		;
	close(fd);
	map[i] = 0;
	error_check_map(map);
	return (map);
}
