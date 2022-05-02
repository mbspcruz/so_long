/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:50:15 by mda-cruz          #+#    #+#             */
/*   Updated: 2022/05/02 19:45:06 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *av, char *file)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (av[i] != file[k])
		i++;
	while (av[i] == file[k])
	{
		if (av [i + 1] == '\0' && file [k + 1] == '\0')
			return (1);
		k++;
		i++;
	}
	return (0);
}

void	error_check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac > 2)
		error_message("Error\nToo many arguments!");
	if (ac <= 1)
		error_message("Error\nAt least one argument must be provided.");
	if (!(is_ber(av[1], ".ber")))
		error_message("Error\nFile needs to be of type '.ber'");
}
