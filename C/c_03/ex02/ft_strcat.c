/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:05:25 by photon            #+#    #+#             */
/*   Updated: 2023/06/27 14:28:53 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*ori_dest;

	ori_dest = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (ori_dest);
}
/*
#include <stdio.h>
int main(){
	// Test case 1: Regular strings
	char dest1[50] = "Hello, ";
	char src1[50] = "World!";
	ft_strcat(dest1, src1);
	printf("Test 1 result: %s\n", dest1); 
	// Expected output: "Hello, World!"

	// Test case 2: Empty source string
	char dest2[50] = "Hello, ";
	char src2[50] = "";
	ft_strcat(dest2, src2);
	printf("Test 2 result: %s\n", dest2); 
	// Expected output: "Hello, "

	// Test case 3: Empty destination string
	char dest3[50] = "";
	char src3[50] = "World!";
	ft_strcat(dest3, src3);
	printf("Test 3 result: %s\n", dest3); 
	// Expected output: "World!"

	// Test case 4: Empty source and destination strings
	char dest4[50] = "";
	char src4[50] = "";
	ft_strcat(dest4, src4);
	printf("Test 4 result: %s\n", dest4);  // Expected output: ""

	// Test case 5: Long strings
	char dest5[100] = "This is a long string. ";
	char src5[100] = "This is another long string.";
	ft_strcat(dest5, src5);
	printf("Test 5 result: %s\n", dest5); 
	// Expected output: "This is a long string. This is another long string."

	// Test case 7: Destination string space exactly fits the source string
	char dest7[10] = "12345";
	char src7[5] = "6789";
	ft_strcat(dest7, src7);
	printf("Test 7 result: %s\n", dest7); // Expected output: "123456789"

	return 0;
}
*/
