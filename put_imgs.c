/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:00:39 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 19:00:59 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_space(t_game *data, int x, int y)
{
	int	width;
	int	height;

	data->sprite.wall = mlx_xpm_file_to_image(data->mlx,
			"sprites/tiles/wall.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->window, data->sprite.wall,
		x * IMG_WDTH, y * IMG_WDTH);
}

void	collectable_space(t_game *data, int x, int y)
{
	int	width;
	int	height;

	data->sprite.colectible = mlx_xpm_file_to_image(data->mlx,
			"sprites/objects/collectible.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->window, data->sprite.colectible,
		x * IMG_WDTH, y * IMG_WDTH);
}

void	exit_space(t_game *data, int x, int y)
{
	int	width;
	int	height;

	data->sprite.exit = mlx_xpm_file_to_image(data->mlx,
			"sprites/tiles/end.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->window, data->sprite.exit,
		x * IMG_WDTH, y * IMG_WDTH);
}

void	player_space(t_game *data, int x, int y)
{
	int	height;
	int	width;

	data->map.map_x = x;
	data->map.map_y = y;
	data->sprite.player = mlx_xpm_file_to_image(data->mlx,
			"sprites/characters/character_side.xpm", &width, &height);
	data->sprite.player_l = mlx_xpm_file_to_image(data->mlx,
			"sprites/characters/character_side_left.xpm", &width, &height);
	data->sprite.player_up = mlx_xpm_file_to_image(data->mlx,
			"sprites/characters/character_back.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->window, data->sprite.player,
		data->map.map_x * IMG_WDTH, data->map.map_y * IMG_WDTH);
}
