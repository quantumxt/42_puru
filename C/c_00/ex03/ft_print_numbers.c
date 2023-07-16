/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:20 by photon            #+#    #+#             */
/*   Updated: 2023/06/21 17:09:18 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	num_disp;

	num_disp = '0';
	while (num_disp <= '9')
	{
		write(1, &num_disp, 1);
		num_disp++;
	}
}
/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
*/
