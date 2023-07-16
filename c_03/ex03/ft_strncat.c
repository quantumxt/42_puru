/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:19:23 by photon            #+#    #+#             */
/*   Updated: 2023/06/27 15:29:52 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*ori_dest;
	unsigned int	i;

	ori_dest = dest;
	i = 0;
	while (*dest)
		dest++;
	while (*src && i < nb)
	{
		*dest = *src;
		i++;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ori_dest);
}
/*
#include <stdio.h>
int main()
{
	char test1[50] = "Hello, ";
	char test2[50] = "Hello, ";
	char src[] = "World!";
	char src2[] = "Cruel World!";

	printf(">> Test 1: Expected output: Hello, Wor\n");
	ft_strncat(test1, src, 3);
	printf("<< Output: %s\n====\n", test1);

	printf(">> Test 2: Expected output: Hello, World!\n");
	ft_strncat(test2, src, 7);
	printf("<< Output: %s\n====\n", test2);

	char test3[50] = "Goodbye, ";
	printf(">> Test 3: Expected output: Goodbye, Cruel World!\n");
	ft_strncat(test3, src2, 50);
	printf("<< Output: %s\n====\n", test3);

	char test4[50] = "";
	printf(">> Test 4: Expected output: World!\n");
	ft_strncat(test4, src, 7);
	printf("<< Output: %s\n====\n", test4);

	char test5[50] = "Bye, ";
	printf(">> Test 5: Expected output: Bye, \n");
	ft_strncat(test5, src, 0);
	printf("<< Output: %s\n====\n", test5);
	return 0;
}
*/
