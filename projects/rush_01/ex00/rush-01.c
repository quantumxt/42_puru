/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcoord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:08:20 by zchia             #+#    #+#             */
/*   Updated: 2023/07/01 22:09:08 by zchia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	check_col_up(int *result, int *input, int pos);
int	check_row_right(int *result, int *input, int pos);
int	check_col_down(int *result, int *input, int pos);
int	check_row_left(int *result, int *input, int pos);

int	is_valid(int *result, int *input, int pos)
{
	if (check_row_left(result, input, pos) == 0)
		return (0);
	if (check_row_right(result, input, pos) == 0)
		return (0);
	if (check_col_up(result, input, pos) == 0)
		return (0);
	if (check_col_down(result, input, pos) == 0)
		return (0);
	return (1);
}

int	have_repeat(int *tab, int pos, int try_num)
{
	int	i;

	i = 0;
	while (i < (pos % 4))
	{
		if (tab[pos - i] == try_num)
			return (1);
		i++;
	}
	i = 0;
	while (i < (pos / 4))
	{
		if (tab[pos - 4 * i] == try_num)
			return (1);
		i++;
	}
	return (0);
}

int	getresult(int *result, int *input, int pos)
{
	int	try_num;

	if (pos == 16)
		return (1);
	try_num = 1;
	while (try_num <= 4)
	{
		if (have_repeat(result, pos, try_num) == 0)
		{
			result[pos] = try_num;
			if (is_valid(result, input, pos) == 1)
			{
				if (getresult(result, input, pos + 1) == 1)
					return (1);
			}
			else
				result[pos] = 0;
		}
		try_num++;
	}
	return (0);
}
