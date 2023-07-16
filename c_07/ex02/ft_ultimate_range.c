/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:45:45 by photon            #+#    #+#             */
/*   Updated: 2023/07/04 12:50:08 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*list;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	list = (int *) malloc((max - min) * sizeof(int));
	if (!list)
		return (-1);
	i = 0;
	*range = list;
	while (min < max)
	{
		(*range)[i] = min++;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	int *q = NULL;
	int	range = ft_ultimate_range(&q, 0,5);
	printf("Num created: %i\n", range);
	for(int i = 0; i< 5; ++i)
	{
		printf("%i -> %i\n", i, q[i]);
	}
	return (0);
}
*/