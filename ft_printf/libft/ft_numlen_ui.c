/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cruz <mda-cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:30:33 by mda-cruz          #+#    #+#             */
/*   Updated: 2021/07/17 00:04:36 by mda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen_ui(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 10)
	{
		count++;
		n /= 10;
	}
	while (n <= 0)
	{
		count += 1;
		n *= -1;
	}
	return (count);
}