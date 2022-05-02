/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:51:32 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 19:46:01 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_foreign_char(char map)
{
	if (map != '0' && map != '1' && map != 'C' && map != 'E' && map != 'P')
		error_message("Error\nStrange character!");
}

void	check_counts(t_game vars)
{
	if (vars.check.count_collectible < 1)
		error_message("Error\nWe need at least one chest!");
	if (vars.check.count_exit < 1)
		error_message("Error\nWe need at least one exit!");
	if (vars.check.count_player != 1)
		error_message("Error\nWe need only one player!");
}

void	check_walls(char **map)
{
	int		x;
	int		y;
	t_game	data;

	window_size(&data, map);
	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) != data.size.size_x)
			error_message("Error\nMap must be a rectangle!");
		x = 0;
		while (map[y][x])
		{
			if (map[0][x] != '1' || map[data.size.size_y - 1][x] != '1')
				error_message("Error\nMap must be surrounded by walls!");
			x++;
		}
		if (map[y][0] != '1' || map[y][data.size.size_x - 1] != '1')
			error_message("Error\nMap must be surrounded by walls!");
		y++;
	}
}

void	error_check_map(char **map)
{
	t_game	var;

	var.check.y = 0;
	var.check.count_player = 0;
	var.check.count_collectible = 0;
	var.check.count_exit = 0;
	check_walls(map);
	while (map[var.check.y])
	{
		var.check.x = 0;
		while (map[var.check.y][var.check.x])
		{
			if (map[var.check.y][var.check.x] == 'P')
				var.check.count_player++;
			if (map[var.check.y][var.check.x] == 'C')
				var.check.count_collectible++;
			if (map[var.check.y][var.check.x] == 'E')
				var.check.count_exit++;
			check_foreign_char(map[var.check.y][var.check.x]);
			var.check.x++;
		}
		var.check.y++;
	}	
	check_counts(var);
}
