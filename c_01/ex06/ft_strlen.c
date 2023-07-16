/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:20 by photon            #+#    #+#             */
/*   Updated: 2023/06/22 23:01:02 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (*str != '\0')
	{
		idx++;
		str++;
	}
	return (idx);
}
/*
#include <stdio.h>
int	main(void)
{
	char	some_str[] = "Hello world!";
	
	printf("Str: %s, len: %d", some_str, ft_strlen(some_str));
	return (0);
}
*/
