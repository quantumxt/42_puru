/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:30:03 by photon            #+#    #+#             */
/*   Updated: 2023/07/13 14:06:32 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_ascend(int *arr, int arr_len, int (*f)(int, int))
{
	int	i;

	i = -1;
	while (++i < arr_len)
	{
		if (f(arr[i], arr[i + 1]) < 0)
			return (1);
		if (f(arr[i], arr[i + 1]) > 0)
			return (0);
	}
	return (0);
}

int	check_sorted(int *arr, int arr_len, int (*f)(int, int))
{
	int	i;
	int	j;
	int	check_ascend;

	i = -1;
	if (arr_len < 2)
		return (1);
	check_ascend = is_ascend(arr, arr_len, f);
	while (++i < arr_len)
	{
		j = i;
		while (++j < arr_len)
		{
			if (f(arr[i], arr[j]) > 0 && check_ascend)
				return (0);
			if (f(arr[i], arr[j]) < 0 && !check_ascend)
				return (0);
		}
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (check_sorted(tab, length, f))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	compare(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int nums[] = {1, 5, 7, 2, 4, 3};
	int nums_a[] = {1, 1, 2, 3, 5, 8};
	int nums_b[] = {8, 5, 3, 2, 1, 0};
	int nums_c[] = {0, 0, 0, 0, 0, 0};
	int nums_d[] = {5};
	int nums_e[] = {5, 4};
	int nums_f[] = {2, 2};
	int nums_g[] = {-1, 4};
	int nums_h[] = {};
	int nums_i[] = {5, 4, 10};

	printf("Unsort: %i\n", ft_is_sort(nums, 6, compare));
	printf("Ascending: %i\n", ft_is_sort(nums_a, 6, compare));
	printf("Descending: %i\n", ft_is_sort(nums_b, 6, compare));
	printf("Same: %i\n", ft_is_sort(nums_c, 6, compare));
	printf("Single: %i\n", ft_is_sort(nums_d, 1, compare));
	printf("Descending double: %i\n", ft_is_sort(nums_e, 2, compare));
	printf("Same double: %i\n", ft_is_sort(nums_f, 2, compare));
	printf("Ascending double: %i\n", ft_is_sort(nums_g, 2, compare));
	printf("Empty: %i\n", ft_is_sort(nums_h, 0, compare));
	printf("Triple unsort: %i\n", ft_is_sort(nums_i, 3, compare));
	return (0);
}
*/
