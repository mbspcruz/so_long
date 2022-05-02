/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:27:33 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 19:47:55 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_bg(t_game *data)
{
	int	width;
	int	height;
	int	i;
	int	z;

	data->sprite.bg = mlx_xpm_file_to_image(data->mlx,
			"sprites/tiles/tile1.xpm", &width, &height);
	i = 0;
	while (i < data->check.y)
	{
		z = 0;
		while (data->check.x > z)
		{
			mlx_put_image_to_window(data->mlx, data->window,
				data->sprite.bg, z, i);
			z += IMG_WDTH;
		}
		i += IMG_WDTH;
	}
}

void	put_tiles(t_game *data)
{
	int	y;
	int	x;

	put_bg(data);
	y = 0;
	while ((data->check.y / IMG_WDTH) > y)
	{
		x = 0;
		while ((data->check.x / IMG_WDTH) > x)
		{
			if (data->map.map[y][x] == '1')
				wall_space(data, x, y);
			else if (data->map.map[y][x] == 'C')
			{
				collectable_space(data, x, y);
				data->check.count_collectible++;
			}
			else if (data->map.map[y][x] == 'E')
				exit_space(data, x, y);
			else if (data->map.map[y][x] == 'P')
				player_space(data, x, y);
			x++;
		}
		y++;
	}
}
