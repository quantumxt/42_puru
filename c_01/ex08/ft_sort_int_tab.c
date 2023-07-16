/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:20 by photon            #+#    #+#             */
/*   Updated: 2023/06/23 13:20:29 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	j = size;
	while (j > 0)
	{
		i = 0;
		while (i < j - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		j--;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	const int	list_len = 9;
	int	some_int[9] = {7,1,9,3,5,2,20,11,4};
	printf("\nBefore:\n");
	for(int i=0; i< list_len; i++){	
		printf("%d, ", some_int[i]);
	}
	ft_sort_int_tab(some_int, list_len);
	printf("\nAfter:\n");
	for(int i=0; i< list_len; i++){	
		printf("%d, ", some_int[i]);
	}
	return (0);
}
*/
