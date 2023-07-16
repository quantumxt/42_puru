/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:29:56 by photon            #+#    #+#             */
/*   Updated: 2023/07/12 14:37:38 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = -1;
	while (++i < length)
		f(tab[i]);
}
/*
#include <unistd.h>

void	prt(int i)
{
	write(1, &"0123456789"[i%10], 1);
	write(1, "\n", 1);
}

int	main(void)
{
	int	ls[10] = {0, 1, 2, 3, 4, 5, 6, 7 ,8, 9};
	ft_foreach(ls, 10, prt);
	return (0);
}
*/
