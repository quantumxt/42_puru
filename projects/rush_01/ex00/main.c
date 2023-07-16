/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:23:14 by zchia             #+#    #+#             */
/*   Updated: 2023/07/02 18:43:03 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
//./rush-01 "1 2 2 2 4 1 3 2 1 2 3 2 3 2 1 3"
//./rush-01 "3 1 2 3 2 4 2 1 2 3 1 2 3 2 2 1"

#include <stdlib.h>
#include <unistd.h>

int	getresult(int *result, int *input, int pos);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	printgrid(int *result, int row, int col)
{
	char	digit;

	if (row == 4)
		return ;
	digit = result[row * 4 + col] + '0';
	write(1, &digit, 1);
	if (col != 3)
		write(1, " ", 1);
	col++;
	if (col == 4)
	{
		write(1, "\n", 1);
		col = 0;
		row++;
	}
	printgrid(result, row, col);
}

int	checkerror(char *input, int size)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if ((i % 2 == 0 && input[i] >= '1' && input[i] <= '4')
			|| (i % 2 == 1 && input[i] == ' '))
			i++;
		else
			return (0);
	}
	if (i != (size * 2) - 1)
		return (0);
	return (1);
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

int	main(int argc, char *argv[])
{
	char	*input;
	int		*myint;
	int		*result;

	if (argc == 2)
	{
		myint = (int *)malloc (16 * sizeof (int));
		result = (int *)malloc (16 * sizeof (int));
		input = argv[1];
		if (checkerror(input, 16) == 0)
			ft_putstr("Error\n");
		else
		{
			grabint(input, myint);
			if (getresult(result, myint, 0) == 1)
				printgrid(result, 0, 0);
			else
				ft_putstr("Error\n");
		}
		free (myint);
		free (result);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
