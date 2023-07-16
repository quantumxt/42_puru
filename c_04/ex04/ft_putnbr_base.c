/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:31:12 by photon            #+#    #+#             */
/*   Updated: 2023/07/07 16:20:25 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	to_num(long n, int base, char *basemap)
{
	char	char_nb;

	if (n >= base)
	{
		to_num(n / base, base, basemap);
		to_num(n % base, base, basemap);
	}
	else
	{
		char_nb = basemap[n % base];
		write(1, &char_nb, 1);
	}
}

int	valid_base(char *str)
{
	int		str_count;
	int		dup_check;

	str_count = 0;
	while (str[str_count])
	{
		if (str[str_count] == '+' || str[str_count] == '-')
			return (-1);
		dup_check = 0;
		while (dup_check < str_count)
		{
			if (str[str_count] == str[dup_check])
				return (-1);
			dup_check++;
		}
		str_count++;
	}
	return (str_count);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_num;

	base_num = valid_base(base);
	if (base_num < 2)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		to_num(- (long) nbr, base_num, base);
	}
	else
	{
		to_num(nbr, base_num, base);
	}
}
/*
#include <stdio.h>
#include <limits.h>
int main() {
    ft_putnbr_base(-123456, "01"); // prints in binary (-11110001001000000)
    printf("\n");
    ft_putnbr_base(255, "0123456789ABCDEF"); // prints in hexadecimal (FF)
    printf("\n");
    ft_putnbr_base(64, "poneyvif"); // prints in "poneyvif" base system (opp)
    printf("\n");
    ft_putnbr_base(64, "poneyvip"); // prints nothing: duplicate
    printf("\n");
    ft_putnbr_base(100, "01"); // Binary (1100100)
    printf("\n");
    ft_putnbr_base(100, "01234567"); // Octal (144)
    printf("\n");
    ft_putnbr_base(100, "0123456789ABCDEF"); // Hexadecimal (64)
    printf("\n");
    ft_putnbr_base(-25, "GHJKLMNP"); // Custom base system (-KH)
    printf("\n");
    ft_putnbr_base(0, "01"); // Binary zero (0)
    printf("\n");
    
    // prints in decimal: 2147483647
    ft_putnbr_base(INT_MAX, "0123456789");
    printf("\n");
    // prints in decimal: -2147483648
    ft_putnbr_base(INT_MIN, "0123456789");
    printf("\n");
    // prints in binary: 1111111111111111111111111111111
    ft_putnbr_base(INT_MAX, "01");
    printf("\n");
    // prints in binary: -10000000000000000000000000000000
    ft_putnbr_base(INT_MIN, "01");
    printf("\n");
    
    // Invalid base test cases
    ft_putnbr_base(100, "0"); // Invalid base (single character)
    printf("\n");
    ft_putnbr_base(100, "0011"); // Invalid base (repeating characters)
    printf("\n");
    ft_putnbr_base(100, "+01"); // Invalid base (contains '+')
    printf("\n");
    ft_putnbr_base(100, "-01"); // Invalid base (contains '-')
    
    return 0;
}
*/
