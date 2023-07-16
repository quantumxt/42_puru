/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:20 by photon            #+#    #+#             */
/*   Updated: 2023/06/24 17:51:52 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	set_count(char *num, char start)
{
	num[0] = start;
	num[1] = num[0] + 1;
	num[2] = num[1] + 1;
}

void	inc_count(char *target, char *next, char threshold)
{
	if (*target < threshold)
		(*target)++;
	else if (*target != threshold - 1)
	{
		(*next)++;
		*target = *next + 1;
	}
}

void	ft_print_comb(void)
{
	char	num[3];

	set_count(num, '0');
	while (num[0] <= '7')
	{	
		if (num[0] < num[1] && num[0] < num[2] && num[1] < num[2])
		{
			write(1, &num, 3);
			if (!(num[0] == '7' && num[1] == '8' && num[2] == '9'))
				write(1, ", ", 2);
		}
		inc_count(&num[2], &num[1], '9');
		if (num[1] > '8')
		{
			num[0]++;
			set_count(num, num[0]);
		}
	}
}
/*
#include <stdio.h>
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/
