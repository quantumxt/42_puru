/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:45:25 by photon            #+#    #+#             */
/*   Updated: 2023/07/13 15:45:29 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "display.h"

void	prt(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	to_num(long n)
{
	char	char_nb;

	if (n >= 10)
	{
		to_num(n / 10);
		to_num(n % 10);
	}
	else
	{
		char_nb = "0123456789"[n % 10];
		write(1, &char_nb, 1);
	}
}

void	print_num(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		to_num(- (long) nbr);
	}
	else
		to_num((long) nbr);
}
