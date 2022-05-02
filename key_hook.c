/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:04:30 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 19:33:58 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	keys(int key, t_game *data)
{
	if (data->map.map[data->map.map_y][data->map.map_x] != 'E')
	{
		if (key == 2 || key == 0 || key == 1 || key == 13)
		{
			ft_printf("%d\n", data->counter);
			check_chests(data, key);
		}
	}
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	return (0);
}

int	ft_close(void)
{
	exit(0);
}
