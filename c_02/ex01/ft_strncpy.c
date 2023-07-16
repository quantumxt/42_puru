/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:47:41 by photon            #+#    #+#             */
/*   Updated: 2023/06/27 10:45:30 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	while (idx < n)
	{
		dest[idx] = '\0';
		idx++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
	// Test case 1:
	// Copy less characters than the length of the source string
	char src1[] = "Hello, World!";
	char dest1[20];
	printf("Test 1:\n");
	printf("Source: '%s', Length to copy: 5\n", src1);
	ft_strncpy(dest1, src1, 5);
	printf("Destination: '%s'\n", dest1);

	// Test case 2:
	// Copy exactly the length of the source string
	char src2[] = "Hello";
	char dest2[20];
	printf("\nTest 2:\n");
	printf("Source: '%s', Length to copy: 5\n", src2);
	ft_strncpy(dest2, src2, 5);
	printf("Destination: '%s'\n", dest2);

	// Test case 3:
	// Copy more characters than the length of the source string
	char src3[] = "Hello";
	char dest3[20];
	printf("\nTest 3:\n");
	printf("Source: '%s', Length to copy: 10\n", src3);
	ft_strncpy(dest3, src3, 10);
	printf("Destination: '%s'\n", dest3);

	// Test case 4:
	// Copy zero characters
	char src4[] = "Hello, World!";
	char dest4[20] = "Initial content";
	printf("\nTest 4:\n");
	printf("Source: '%s', Length to copy: 0\n", src4);
	ft_strncpy(dest4, src4, 0);
	printf("Destination: '%s'\n", dest4);
	
	// Test case 5:
	// Empty source string
	char src5[] = "";
	char dest5[20] = "Initial content";
	printf("\nTest 5:\n");
	printf("Source: '%s', Length to copy: 10\n", src5);
	ft_strncpy(dest5, src5, 10);
	printf("Destination: '%s'\n", dest5);

	// Test case 6:
	// Size of 'n' is greater than the size of the destination buffer
	char src6[] = "This string is longer than the destination buffer.";
	char dest6[20];
	printf("\nTest 6:\n");
	printf("Source: '%s', Length to copy: 50\n", src6);
	ft_strncpy(dest6, src6, 50); // This should ideally not cause a buffer overflow
	printf("Destination: '%s'\n", dest6);

	return 0;
}
*/
