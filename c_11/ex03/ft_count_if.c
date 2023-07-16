/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:23:49 by photon            #+#    #+#             */
/*   Updated: 2023/07/13 13:26:39 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (++i < length)
		if ((*f)(tab[i]) != 0)
			count++;
	return (count);
}
/*
#include <stdio.h>
int	more_than_five(char *c)
{
	int	count;

	count = 0;
	while (*c++)
		count++;
	return (count >= 5);
}
int	main(void)
{
	char* tab[] = {"Hello", "World", "42", "SG", "contemplation", NULL};
	int result = ft_count_if(tab, 5, more_than_five);
	printf("%d\n", result);  // Should print "1"

	char* tab2[] = {"good", "word", "bye", "now", "", NULL};
	result = ft_count_if(tab2, 5, more_than_five);
	printf("%d\n", result);  // Should print "0"

	return (0);
}
*/
