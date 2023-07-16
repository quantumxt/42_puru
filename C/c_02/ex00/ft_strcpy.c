/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:47:41 by photon            #+#    #+#             */
/*   Updated: 2023/06/24 18:20:58 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_ori;

	dest_ori = dest;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_ori);
}
/*
#include <stdio.h>
int main(void)
{
	char j[] = "Hello";
	char k[] = "Bye";
	printf("%s\n", j);
	ft_strcpy(j, k);
	printf("%s\n", j);
	return 0;
}
*/
