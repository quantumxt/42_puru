/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:50:29 by photon            #+#    #+#             */
/*   Updated: 2023/06/27 20:23:45 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while ((*s1 || *s2) && i < n)
		{
			if (*s1 != *s2)
				return (*s1 - *s2);
			s1++;
			s2++;
			i++;
		}
		if (i == n)
			return (0);
		else
			return (*s1 - *s2);
	}
	else
		return (0);
}
/*
#include <assert.h>
#include <stdio.h>
int main() {
	assert(ft_strncmp("Hello", "Hello", 5) == 0);
	assert(ft_strncmp("Hello", "Hello", 3) == 0);
	assert(ft_strncmp("Hello", "World", 5) < 0);
	assert(ft_strncmp("Hello", "World", 2) < 0);
	assert(ft_strncmp("World", "Hello", 5) > 0);
	assert(ft_strncmp("World", "Hello", 2) > 0);
	assert(ft_strncmp("", "", 0) == 0);
	assert(ft_strncmp("", "Hell", 4) < 0);
	assert(ft_strncmp("Hello", "", 5) > 0);
	assert(ft_strncmp("Hell", "Hello", 4) == 0);
	assert(ft_strncmp("Hello", "Hell", 4) == 0);
	assert(ft_strncmp("Hello", "World", 0) == 0);

	printf("All tests passed successfully.\n");

	return 0;
}
*/
