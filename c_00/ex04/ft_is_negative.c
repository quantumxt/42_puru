/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:20 by photon            #+#    #+#             */
/*   Updated: 2023/06/21 17:20:22 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	show_n;
	char	show_p;

	show_n = 'N';
	show_p = 'P';
	if (n < 0)
		write(1, &show_n, 1);
	else
		write(1, &show_p, 1);
}
/*
int	main(void)
{
	ft_is_negative(2);
	ft_is_negative(-10);
	ft_is_negative(0);
	return (0);
}
*/
