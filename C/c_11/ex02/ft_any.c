/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:45:44 by photon            #+#    #+#             */
/*   Updated: 2023/07/13 13:20:04 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = -1;
	while (tab[++i])
		if ((*f)(tab[i]) != 0)
			return (1);
	return (0);
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
	char* tab[] = {"Hello", "World", "42", "SG", NULL};
	int result = ft_any(tab, more_than_five);
	printf("%d\n", result);  // Should print "1"

	char* tab2[] = {"good", "word", "bye", "now", NULL};
	result = ft_any(tab2, more_than_five);
	printf("%d\n", result);  // Should print "0"

	return (0);
}
*/
