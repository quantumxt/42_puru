/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:10:17 by photon            #+#    #+#             */
/*   Updated: 2023/07/04 12:43:48 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*list;
	int	i;

	if (min >= max)
		return (NULL);
	list = (int *) malloc((max - min) * sizeof(int));
	if (!list)
		return (NULL);
	i = 0;
	while (min < max)
	{
		list[i] = min++;
		i++;
	}
	return (list);
}
/*
#include <stdio.h>
int	main(void)
{
	int	*test = ft_range(0,8);
	for(int i = 0; i< 7; ++i)
	{
		printf("%i -> %i\n", i, test[i]);
	}
	return (0);
}
*/
