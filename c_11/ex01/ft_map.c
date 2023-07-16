/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:39:38 by photon            #+#    #+#             */
/*   Updated: 2023/07/12 15:11:04 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*int_arr;
	int	i;

	int_arr = (int *) malloc(length * sizeof(int));
	if (!int_arr)
		return (NULL);
	i = -1;
	while (++i < length)
		int_arr[i] = (*f)(tab[i]);
	return (int_arr);
}
/*
#include <stdio.h>

int	prt(int i)
{
	printf("%c\n", "0123456789"[i%10]);
	return (i);
}

int	main(void)
{
	int	ls[10] = {0, 1, 2, 3, 4, 5, 6, 7 ,8, 9};
	printf("Ori addr: %p", &ls);
	int	*new_ls = ft_map(ls, 10, prt);
	printf("New addr: %p", &new_ls);
	free(new_ls);
	return (0);
}
*/
