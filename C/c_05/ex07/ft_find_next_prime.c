/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:13:41 by photon            #+#    #+#             */
/*   Updated: 2023/07/03 19:21:41 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i <= nb / i)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	long long	next;

	next = nb;
	if (next <= 2)
		return (2);
	if (next % 2 == 0)
		next++;
	while (!ft_is_prime(next))
		next += 2;
	return (next);
}
/*
#include <stdio.h>
int	main(void)
{
	for(int i = 0; i < 100; ++i)
	{
			printf("%i -> %i\n", i, ft_find_next_prime(i));
	}
	return (0);
}
*/
