/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:11:22 by photon            #+#    #+#             */
/*   Updated: 2023/06/26 19:11:55 by photon           ###   ########.fr       */
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
#include <stdio.h>
#include <limits.h>
int main(void)
{
    printf("Printing 0:\n");
    ft_putnbr(0);
    printf("\nPrinting 15:\n");
    ft_putnbr(15);
    printf("\nPrinting 16:\n");
    ft_putnbr(16);
    printf("\nPrinting 255:\n");
    ft_putnbr(255);
    printf("\nPrinting -10:\n");
    ft_putnbr(-10);
    printf("\nPrinting INT_MAX:\n");
    ft_putnbr(INT_MAX);
    printf("\nPrinting INT_MIN:\n");
    ft_putnbr(INT_MIN);
    return (0);
}
*/
