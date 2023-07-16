/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:20 by photon            #+#    #+#             */
/*   Updated: 2023/06/22 20:24:06 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>
int	main(void)
{
	int	nums[4];
	
	nums[0] = 100;
	nums[1] = 50;
	printf("a: %i, b:%i\n", nums[0], nums[1]);
	ft_div_mod(nums[0], nums[1], &nums[2], &nums[3]);
	printf("Div: %i, Mod: %i\n", nums[2], nums[3]);
	
	nums[1] += 7;
	printf("a: %i, b:%i\n", nums[0], nums[1]);
	ft_div_mod(nums[0], nums[1], &nums[2], &nums[3]);
	printf("Div: %i, Mod: %i\n", nums[2], nums[3]);
	return (0);
}
*/
