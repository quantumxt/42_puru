/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:31:14 by photon            #+#    #+#             */
/*   Updated: 2023/07/03 12:06:45 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index < 3)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char ** argv)
{
	if (argc == 2)
	{
		int	in_num;

		in_num = atoi(argv[1]);
		printf("i: %i -> %i\n", in_num, ft_fibonacci(in_num));
	}
	else
	{
		for (int i = -2; i < 45; ++i)
			printf(">> %02i: %i\n", i, ft_fibonacci(i));
	}
	return (0);
}
*/
