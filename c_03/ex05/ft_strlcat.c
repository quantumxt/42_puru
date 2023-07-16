/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:45:06 by photon            #+#    #+#             */
/*   Updated: 2023/06/27 20:12:44 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int	length;

	length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	total_len;

	src_len = str_len(src);
	dest_len = str_len(dest);
	total_len = dest_len + src_len;
	if (size <= dest_len)
		return (src_len + size);
	while (*src && dest_len + 1 < size)
	{
		dest[dest_len] = *src;
		dest_len++;
		src++;
	}
	dest[dest_len] = '\0';
	return (total_len);
}
/*
#include <stdio.h>
int	main(void)
{
	char dst[20] = "Hello, ";
	char src[] = "World!";
	size_t ret;

	ret = ft_strlcat(dst, src, sizeof(dst));

	printf("Updated dst = %s\n", dst);
	printf("Return value = %lu\n", ret);
	return	0;
}
*/
