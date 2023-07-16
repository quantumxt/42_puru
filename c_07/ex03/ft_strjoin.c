/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:24:39 by photon            #+#    #+#             */
/*   Updated: 2023/07/04 16:22:55 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	f_cat(char *dest, char *src)
{
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}

int	len(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int	total_len(int size, char **strs)
{
	int	total;
	int	i;

	total = 0;
	i = -1;
	while (++i < size)
		total += len(strs[i]);
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ori_ptr;
	char	*new_str;
	int		new_len;
	int		i;

	if (size == 0)
		new_len = 1;
	else
		new_len = total_len(size, strs) + (size - 1) * len(sep) + 1;
	new_str = (char *) malloc(new_len * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[0] = '\0';
	if (size == 0)
		return (new_str);
	ori_ptr = new_str;
	i = -1;
	while (++i < size)
	{
		f_cat(new_str, strs[i]);
		if (i < size - 1)
			f_cat(new_str, sep);
	}
	return (ori_ptr);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char *sep = "-";
	char *strings[] = {"Hello", "World", "C", "join"};
	int size = 4;

	char *result = ft_strjoin(size, strings, sep);

	if (strcmp(result, "Hello-World-C-join") == 0)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");

	free(result); // Free the memory!

	return 0;
}
*/
