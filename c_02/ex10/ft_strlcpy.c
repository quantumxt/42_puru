/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:23:11 by photon            #+#    #+#             */
/*   Updated: 2023/06/26 17:53:52 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	str_len;

	str_len = 0;
	while (src[str_len])
		str_len++;
	if (size > 0)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		if (str_len >= size)
			dest[size - 1] = '\0';
		else
			dest[str_len] = '\0';
	}
	return (str_len);
}
/*
#include <stdio.h>
int main(void){
	char dest[20];

	char src[][150] = {
        "Hello, World!",
        "Lorem ipsum dolor sit amet",
        "",
        "1234567890",
        "This is a long string that exceeds the destination size",
        "Exactly20characters!",
        "Short"
 	};
    
	for (int i = 0; i < 7; i++) {
		printf("Src: %s\n", src[i]);
		unsigned int result = ft_strlcpy(dest, src[i], sizeof(dest));
		printf("Result: %s\n", dest);
		printf("Length: %u\n", result);
		printf("\n");
    	}

	return 0;
}
*/
