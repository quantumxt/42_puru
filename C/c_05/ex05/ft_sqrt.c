/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:07:39 by photon            #+#    #+#             */
/*   Updated: 2023/07/03 12:20:51 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	start;
	long long	end;
	long long	mid;

	start = 0;
	end = (long long) nb;
	if (nb == 0 || nb == 1)
		return (nb);
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (mid * mid == nb)
			return ((int) mid);
		else if (mid * mid < nb)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}
/*
int	ft_sqrt(int nb)
{
	long long	root;

	root = 1;
	if (nb == 0 || nb == 1)
		return (nb);
	while (root * root <= (long long) nb)
	{
		if (root * root == (long long) nb)
			return (root);
		root++;
	}
	return (0);
}

#include <stdio.h>
// 10000000 iterations:
// Brute force: 11.7s
// Binary Search: 0.358s

// 50000000 iterations:
// Brute force: 2m9.668s
// Binary Search: 1.792s
int	main(void)
{
	for (int i = 0; i < 50000000; ++i){
		int res = ft_sqrt(i);
		if (res!=0)
			printf("%d: %i\r", i, res);
	}
	return (0);
}
*/
