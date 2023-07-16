/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:11:55 by photon            #+#    #+#             */
/*   Updated: 2023/07/05 17:01:44 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	prt(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	to_num(int n)
{
	char	char_nb;

	if (n >= 10)
	{
		to_num(n / 10);
		to_num(n % 10);
	}
	else
	{
		char_nb = n + '0';
		write(1, &char_nb, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		prt(par[i].str);
		to_num(par[i].size);
		write(1, "\n", 1);
		prt(par[i].copy);
		i++;
	}
}
