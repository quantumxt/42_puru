/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:23:51 by photon            #+#    #+#             */
/*   Updated: 2023/06/30 14:45:45 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb > 1)
		return (nb * ft_recursive_factorial(nb - 1));
	else
		return (1);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i", ft_recursive_factorial(atoi(argv[1])));
	return (0);
}
*/
