/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:22:35 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 19:42:53 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	error_message(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_game	data;

	error_check_args(ac, av);
	data.map.map = read_map(av[1], data);
	data.mlx = mlx_init();
	window_size(&data, data.map.map);
	data.window = mlx_new_window(data.mlx, data.check.x,
			data.check.y, "so_long");
	put_tiles(&data);
	mlx_key_hook(data.window, *keys, &data);
	mlx_hook(data.window, 17, 0, ft_close, 0);
	mlx_loop(data.mlx);
}
