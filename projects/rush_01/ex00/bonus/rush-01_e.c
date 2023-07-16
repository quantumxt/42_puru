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

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	check_col_up(int *result, int *input, int pos, int size);
int	check_row_right(int *result, int *input, int pos, int size);
int	check_col_down(int *result, int *input, int pos, int size);
int	check_row_left(int *result, int *input, int pos, int size);

int	is_valid(int *result, int *input, int pos, int size)
{
	if (check_row_left(result, input, pos, size) == 0)
		return (0);
	if (check_row_right(result, input, pos, size) == 0)
		return (0);
	if (check_col_up(result, input, pos, size) == 0)
		return (0);
	if (check_col_down(result, input, pos, size) == 0)
		return (0);
	return (1);
}

void	printgrid(int *result, int row, int col, int size)
{
	char	digit;

	if (row == (size / 4))
		return ;
	digit = result[row * (size / 4) + col] + '0';
	write(1, &digit, 1);
	if (col != (size / 4) - 1)
		write(1, " ", 1);
	col++;
	if (col == (size / 4))
	{
		write(1, "\n", 1);
		col = 0;
		row++;
	}
	printgrid(result, row, col, size);
}

void	grabint(char *str, int *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			result[j] = str[i] - '0';
			j++;
		}
		i++;
	}
}

int	checksign(char *str, int *pos)
{
	int	sign;

	sign = 1;
	while (str[*pos] != '\0')
	{
		if (str[*pos] == '-')
		{
			sign = sign * -1;
			*pos = *pos + 1;
		}
		else if (str[*pos] == ' ' || str[*pos] == '+')
			*pos = *pos + 1;
		else if (str[*pos] >= '0' && str[*pos] <= '9')
			return (sign);
		else
			return (0);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	sign;
	int	i;

	nbr = 0;
	i = 0;
	sign = checksign(str, &i);
	if (sign != 0)
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			nbr = nbr * 10 + (str[i] - '0');
			i++;
		}
	}
	return (sign * nbr);
}
