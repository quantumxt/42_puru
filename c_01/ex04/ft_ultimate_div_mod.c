/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:20 by photon            #+#    #+#             */
/*   Updated: 2023/06/22 20:41:11 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	num[2];

	num[0] = *a;
	num[1] = *b;
	*a = num[0] / num[1];
	*b = num[0] % num[1];
}
/*
#include <stdio.h>
int	main(void)
{
	int	nums[2];
	
	nums[0] = 100;
	nums[1] = 50;
	printf("a: %i, b:%i\n", nums[0], nums[1]);
	ft_ultimate_div_mod(&nums[0], &nums[1]);
	printf("Div: %i, Mod: %i\n", nums[0], nums[1]);
	nums[1] += 5;	
	printf("a: %i, b:%i\n", nums[0], nums[1]);
	ft_ultimate_div_mod(&nums[0], &nums[1]);
	printf("Div: %i, Mod: %i\n", nums[0], nums[1]);
	return (0);
}
*/
