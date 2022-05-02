/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:12:59 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 19:46:46 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_game *data)
{
	int	width;
	int	height;

	data->sprite.win = mlx_xpm_file_to_image(data->mlx,
			"sprites/characters/win.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->window, data->sprite.bg,
		data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
	mlx_put_image_to_window(data->mlx, data->window, data->sprite.exit,
		data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
	mlx_put_image_to_window(data->mlx, data->window, data->sprite.win,
		data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
	ft_printf("You used %d moves, think you can do better?\nPress 'ESC' to quit",
		data->counter);
}

void	turn_chests(t_game *data)
{
	if (data->map.map[data->map.map_y][data->map.map_x] == 'C')
	{
		data->map.map[data->map.map_y][data->map.map_x] = '0';
		data->check.count_collectible--;
	}
}

void	check_chests(t_game *data, int key)
{
	turn_chests(data);
	if ((key == 2 && data->map.map[data->map.map_y][data->map.map_x + 1] == 'E')
		|| (key == 0 && data->map.map[data->map.map_y]
			[data->map.map_x - 1] == 'E')
		|| (key == 1 && data->map.map[data->map.map_y + 1]
			[data->map.map_x] == 'E')
		|| (key == 13 && data->map.map[data->map.map_y - 1]
			[data->map.map_x] == 'E'))
	{
		if (data->check.count_collectible != 0)
		{
			mlx_put_image_to_window(data->mlx, data->window,
				data->sprite.player, data->map.map_x * IMG_WDTH,
				data->map.map_y * IMG_WDTH);
			ft_printf("You still have %d chest(s) to pick up!\n",
				data->check.count_collectible);
		}
		else if (data->check.count_collectible == 0)
		{
			move_player(data, key);
			win(data);
		}
	}
	else
		move_player(data, key);
}
