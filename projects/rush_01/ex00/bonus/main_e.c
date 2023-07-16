/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:23:14 by zchia             #+#    #+#             */
/*   Updated: 2023/07/01 15:56:14 by zchia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" 16 | cat -e
//./rush-01 "1 2 2 2 4 1 3 2 1 2 3 2 3 2 1 3" 16 | cat -e
//./rush-01 "3 1 2 3 2 4 2 1 2 3 1 2 3 2 2 1" 16 | cat -e
//./rush-01 "3 1 2 2 3 3 2 1 3 2 2 2 1 3 3 3 2 2 1 3" 20 | cat -e
//./rush-01 "2 2 2 4 3 1 2 3 2 1 3 3 2 2 3 1 3 3 1 3 2 4 3 2" 24 | cat -e

#include <stdlib.h>
#include <unistd.h>

void	printgrid(int *result, int row, int col, int size);
void	grabint(char *str, int *result);
int		ft_atoi(char *str);
int		have_repeat(int *tab, int pos, int try_num, int size);
int		is_valid(int *result, int *input, int pos, int size);

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

int	checkerror(char *input, int size)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if ((i % 2 == 0 && input[i] >= '1' && input[i] <= '1' + size / 4)
			|| (i % 2 == 1 && input[i] == ' '))
			i++;
		else
			return (0);
	}
	if (i != (size * 2) - 1)
		return (0);
	return (1);
}

int	getresult(int *result, int *input, int pos, int size)
{
	int	try_num;

	if (pos == (size * size / 16))
		return (1);
	try_num = 1;
	while (try_num <= (size / 4))
	{
		if (have_repeat(result, pos, try_num, size) == 0)
		{
			result[pos] = try_num;
			if (is_valid(result, input, pos, size) == 1)
			{
				if (getresult(result, input, pos + 1, size) == 1)
					return (1);
			}
			else
				result[pos] = 0;
		}
		try_num++;
	}
	return (0);
}

void	run_rush(char *input, int size)
{
	int	*myint;
	int	*result;

	myint = (int *)malloc (size * sizeof (int));
	result = (int *)malloc ((size * size / 16) * sizeof (int));
	grabint(input, myint);
	if (getresult(result, myint, 0, size) == 1)
		printgrid(result, 0, 0, size);
	else
		ft_putstr("Error\n");
	free (myint);
	free (result);
}

int	main(int argc, char *argv[])
{
	char	*input;
	int		size;

	if (argc == 3)
		size = ft_atoi(argv[2]);
	else if (argc == 2)
		size = 16;
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
	input = argv[1];
	if (checkerror(input, size) == 0)
		ft_putstr("Error\n");
	else
		run_rush(input, size);
	return (0);
}
