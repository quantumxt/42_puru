/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:24:32 by photon            #+#    #+#             */
/*   Updated: 2023/06/25 14:24:58 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_up(char st)
{
	return (st >= 'A' && st <= 'Z');
}

int	is_low(char st)
{
	return (st >= 'a' && st <= 'z');
}

int	is_num(char st)
{
	return (st >= '0' && st <= '9');
}

char	*ft_strcapitalize(char *str)
{
	char	*ori_ptr;
	int		f_start;

	ori_ptr = str;
	f_start = 1;
	while (*str)
	{
		if ((is_up(*str) || is_low(*str) || is_num(*str)))
		{	
			if (f_start)
			{
				if (is_low(*str))
					*str -= 32;
			}
			else if (is_up(*str))
				*str += 32;
			f_start = 0;
		}
		else
		{
			f_start = 1;
		}
		str++;
	}
	return (ori_ptr);
}
/*
#include <stdio.h>
int main(){
	char a[] = "ABcg hsjHjs* 88wwuU";
	char b[] = "ghi387 h8 d83 8dfh8s";
	char c[] = "??eE3 h33? ohho";
	printf("%s ", a);
	printf("-> %s\n", ft_strcapitalize(a));
	printf("%s ", b);
	printf("-> %s\n", ft_strcapitalize(b));
	printf("%s ", c);
	printf("-> %s\n", ft_strcapitalize(c));
	return 0;
}
*/
