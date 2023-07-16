/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:24:32 by photon            #+#    #+#             */
/*   Updated: 2023/06/24 21:36:57 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upper(char st)
{
	return (st >= 'A' && st <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	char	*ori_ptr;

	ori_ptr = str;
	while (*str)
	{
		if (is_upper(*str))
			*str += 32;
		str++;
	}
	return (ori_ptr);
}
/*
#include <stdio.h>
int main(){
	char a[] = "ABFDFGWF";
	char b[] = "ghiFXs sdhGG";
	char c[] = "jdeE3 h33? oo";
	printf("%s ", a);
	printf("-> %s\n", ft_strlowcase(a));
	printf("%s ", b);
	printf("-> %s\n", ft_strlowcase(b));
	printf("%s ", c);
	printf("-> %s\n", ft_strlowcase(c));
	return 0;
}
*/
