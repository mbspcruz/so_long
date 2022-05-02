/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:35:55 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 18:53:11 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_size(t_game *data, char **map)
{
	data->check.y = 0;
	data->check.x = 0;
	data->size.size_x = 0;
	data->size.size_y = 0;
	while (map[data->check.y])
	{
		while (map[data->check.y][data->check.x])
			data->check.x++;
		data->check.y++;
	}
	data->size.size_y = data->check.y;
	data->size.size_x = data->check.x;
	data->check.y *= IMG_WDTH;
	data->check.x *= IMG_WDTH;
	data->counter = 1;
}
