/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:47:13 by photon            #+#    #+#             */
/*   Updated: 2023/06/27 16:09:12 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char *src, char *tofind)
{
	char	*tmp_src;
	char	*tmp_tofind;

	tmp_src = src;
	tmp_tofind = tofind;
	while (*tmp_tofind && *tmp_src)
	{
		if (*tmp_src != *tmp_tofind)
			break ;
		tmp_src++;
		tmp_tofind++;
	}
	if (!*tmp_tofind)
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (check(str, to_find))
			return (str);
		str++;
	}
	return (0);
}
/*
#include <stdio.h>
int main() {
	char str1[] = "Hello, World!";
	char find1[] = "World";
	char *res1 = ft_strstr(str1, find1);
	printf("Test 1: Source text: %s, (To find: %s)\n", str1, find1);
	printf("Expected: World!\n");
	printf("Output: %s\n====\n", res1);

	char str2[] = "abcabcabc";
	char find2[] = "abc";
	char *res2 = ft_strstr(str2, find2);
	printf("Test 2: Source text: %s, (To find: %s)\n", str2, find2);
	printf("Expected: abcabcabc\n");
	printf("Output: %s\n====\n", res2);

	char str3[] = "This is a test.";
	char find3[] = "test";
	char *res3 = ft_strstr(str3, find3);
	printf("Test 3: Source text: %s, (To find: %s)\n", str3, find3);
	printf("Expected: test.\n");
	printf("Output: %s\n====\n", res3);

	char str4[] = "No match here";
	char find4[] = "yes";
	char *res4 = ft_strstr(str4, find4);
	printf("Test 4: Source text: %s, (To find: %s)\n", str4, find4);
	printf("Expected: (null)\n");
	printf("Output: %s\n====\n", res4);

	char str5[] = "Empty search should return original string";
	char find5[] = "";
	char *res5 = ft_strstr(str5, find5);
	printf("Test 5: Source text: %s, (To find: %s)\n", str5, find5);
	printf("Expected: Empty search should return original string\n");
	printf("Output: %s\n====\n", res5);

	char str6[] = "short";
	char find6[] = "abcabcabcabc";
	char *res6 = ft_strstr(str6, find6);
	printf("Test 6: Source text: %s, (To find: %s)\n", str6, find6);
	printf("Expected: (null)\n");
	printf("Output: %s\n====\n", res6 ? res6 : "(null)");

	return 0;
}
*/
