/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:02:32 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 19:22:00 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *data, int key)
{
	if (key == 0 || key == 2)
		move_player_x(data, key);
	if (key == 1 || key == 13)
		move_player_y(data, key);
}

void	move_player_x(t_game *data, int key)
{
	mlx_put_image_to_window(data->mlx, data->window, data->sprite.bg,
		data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
	if (key == 2 && data->map.map[data->map.map_y][data->map.map_x + 1] != '1')
	{
		data->map.map_x += 1;
		mlx_put_image_to_window(data->mlx, data->window, data->sprite.player,
			data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
		data->counter++;
	}
	else if (key == 0 && data->map.map[data->map.map_y]
		[data->map.map_x - 1] != '1')
	{
		data->map.map_x -= 1;
		mlx_put_image_to_window(data->mlx, data->window, data->sprite.player_l,
			data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
		data->counter++;
	}
	if (key == 2 && data->map.map[data->map.map_y][data->map.map_x + 1] == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->sprite.player,
			data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
	else if (key == 0 && data->map.map[data->map.map_y]
		[data->map.map_x - 1] == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->sprite.player_l,
			data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
}

void	move_player_y(t_game *data, int key)
{
	mlx_put_image_to_window(data->mlx, data->window, data->sprite.bg,
		data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
	if (key == 1 && data->map.map[data->map.map_y + 1][data->map.map_x] != '1')
	{
		data->map.map_y += 1;
		mlx_put_image_to_window(data->mlx, data->window, data->sprite.player,
			data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
		data->counter++;
	}
	else if (key == 13 && data->map.map[data->map.map_y - 1]
		[data->map.map_x] != '1')
	{
		data->map.map_y -= 1;
		mlx_put_image_to_window(data->mlx, data->window, data->sprite.player_up,
			data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
		data->counter++;
	}
	if (key == 1 && data->map.map[data->map.map_y + 1][data->map.map_x] == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->sprite.player,
			data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
	else if (key == 13 && data->map.map[data->map.map_y - 1]
		[data->map.map_x] == '1')
		mlx_put_image_to_window(data->mlx, data->window, data->sprite.player_up,
			data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
}
