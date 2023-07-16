/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:36:20 by photon            #+#    #+#             */
/*   Updated: 2023/06/22 23:02:25 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	idx;
	int	tmp;

	idx = 0;
	while (idx < size / 2)
	{
		tmp = tab[size - idx - 1];
		tab[size - idx - 1] = tab[idx];
		tab[idx] = tmp;
		idx++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	some_int[5] = {1,1,2,3,5};
	printf("\nBefore:\n");
	for(int i=0; i< 5; i++){	
		printf("%d, ", some_int[i]);
	}
	ft_rev_int_tab(some_int, 5);
	printf("\nAfter:\n");
	for(int i=0; i< 5; i++){	
		printf("%d, ", some_int[i]);
	}
	return (0);
}
*/
