/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:16:59 by photon            #+#    #+#             */
/*   Updated: 2023/06/28 11:57:12 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char *a, int l)
{
	write(1, a, l);
}

void	show_num(int a, int is_neg)
{
	char	num_disp[12];
	int		idx;

	idx = 0;
	num_disp[11] = '\0';
	while (a != 0)
	{
		num_disp[10 - idx++] = (a % 10) + '0';
		a /= 10;
	}
	if (is_neg)
		num_disp[10 - idx++] = '-';
	print_char(num_disp + (11 - idx), idx);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		print_char("0", 1);
		return ;
	}
	else if (nb < 0)
	{
		if (nb == -2147483648)
		{
			print_char("-2147483648", 11);
			return ;
		}
		nb *= -1;
		show_num(nb, 1);
	}
	else
		show_num(nb, 0);
}
/*
#include <limits.h>
int	main(void)
{

	// Pos num
	ft_putnbr(1994987);
	write(1, "\n", 1);
	ft_putnbr(1618);
	write(1, "\n", 1);
	// Zero
	ft_putnbr(0);
	write(1, "\n", 1);
	// Neg
	ft_putnbr(-10);
	write(1, "\n", 1);
	ft_putnbr(-314159);
	write(1, "\n", 1);
	// Extreme
	ft_putnbr(INT_MAX);
	write(1, "\n", 1);
	ft_putnbr(INT_MIN);
	write(1, "\n", 1);
	
	// Let's loop!
	// Took around 83m10.560s to complete
	for (int i = INT_MIN; i< INT_MAX; i++){
		ft_putnbr(i);
		write(1, "\r", 2);
	}
}
*/
