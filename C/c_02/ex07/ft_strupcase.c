/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:24:32 by photon            #+#    #+#             */
/*   Updated: 2023/06/24 21:33:46 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower(char st)
{
	return (st >= 'a' && st <= 'z');
}

char	*ft_strupcase(char *str)
{
	char	*ori_ptr;

	ori_ptr = str;
	while (*str)
	{
		if (is_lower(*str))
			*str -= 32;
		str++;
	}
	return (ori_ptr);
}
/*
#include <stdio.h>
int main(){
	char a[] = "abcdefghijk";
	char b[] = "ghiFXs sdhGG";
	char c[] = "jdeE3 h33? oo";
	printf("%s ", a);
	printf("-> %s\n", ft_strupcase(a));
	printf("%s ", b);
	printf("-> %s\n", ft_strupcase(b));
	printf("%s ", c);
	printf("-> %s\n", ft_strupcase(c));
	return 0;
}
*/
