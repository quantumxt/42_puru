/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:08:59 by zchia             #+#    #+#             */
/*   Updated: 2023/07/02 16:09:08 by zchia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	have_repeat(int *tab, int pos, int try_num, int size)
{
	int	i;

	i = 0;
	while (i < (pos % (size / 4)))
	{
		if (tab[pos - i] == try_num)
			return (1);
		i++;
	}
	i = 0;
	while (i < (pos / (size / 4)))
	{
		if (tab[pos - (size / 4) * i] == try_num)
			return (1);
		i++;
	}
	return (0);
}

int	check_col_up(int *result, int *input, int pos, int size)
{
	int	can_view;
	int	count;
	int	i;

	if (pos / (size / 4) == (size / 4) - 1)
	{
		i = 0;
		can_view = 0;
		count = 0;
		while (i < (size / 4))
		{
			if (result[i * (size / 4) + pos % (size / 4)] > can_view)
			{
				can_view = result[i * (size / 4) + pos % (size / 4)];
				count++;
			}
			i++;
		}
		if (input[pos % (size / 4)] != count)
			return (0);
	}
	return (1);
}

int	check_row_right(int *result, int *input, int pos, int size)
{
	int	can_view;
	int	count;
	int	i;

	if (pos % (size / 4) == (size / 4) - 1)
	{
		i = (size / 4) - 1;
		can_view = 0;
		count = 0;
		while (i >= 0)
		{
			if (result[pos / (size / 4) * (size / 4) + i] > can_view)
			{
				can_view = result[pos / (size / 4) * (size / 4) + i];
				count++;
			}
			i--;
		}
		if (input[(size / 4) * 3 + pos / (size / 4)] != count)
			return (0);
	}
	return (1);
}

int	check_col_down(int *result, int *input, int pos, int size)
{
	int	can_view;
	int	count;
	int	i;

	if (pos / (size / 4) == (size / 4) - 1)
	{
		i = (size / 4) - 1;
		can_view = 0;
		count = 0;
		while (i >= 0)
		{
			if (result[i * (size / 4) + pos % (size / 4)] > can_view)
			{
				can_view = result[i * (size / 4) + pos % (size / 4)];
				count++;
			}
			i--;
		}
		if (input[(size / 4) + pos % (size / 4)] != count)
			return (0);
	}
	return (1);
}

int	check_row_left(int *result, int *input, int pos, int size)
{
	int	can_view;
	int	count;
	int	i;

	if (pos % (size / 4) == (size / 4) - 1)
	{
		i = 0;
		can_view = 0;
		count = 0;
		while (i < (size / 4))
		{
			if (result[pos / (size / 4) * (size / 4) + i] > can_view)
			{
				can_view = result[pos / (size / 4) * (size / 4) + i];
				count++;
			}
			i++;
		}
		if (input[(size / 4) * 2 + pos / (size / 4)] != count)
			return (0);
	}
	return (1);
}
