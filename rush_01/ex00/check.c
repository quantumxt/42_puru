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

int	check_col_up(int *result, int *input, int pos)
{
	int	can_view;
	int	count;
	int	i;

	if (pos / 4 == 3)
	{
		i = 0;
		can_view = 0;
		count = 0;
		while (i < 4)
		{
			if (result[i * 4 + pos % 4] > can_view)
			{
				can_view = result[i * 4 + pos % 4];
				count++;
			}
			i++;
		}
		if (input[pos % 4] != count)
			return (0);
	}
	return (1);
}

int	check_row_right(int *result, int *input, int pos)
{
	int	can_view;
	int	count;
	int	i;

	if (pos % 4 == 3)
	{
		i = 3;
		can_view = 0;
		count = 0;
		while (i >= 0)
		{
			if (result[pos / 4 * 4 + i] > can_view)
			{
				can_view = result[pos / 4 * 4 + i];
				count++;
			}
			i--;
		}
		if (input[12 + pos / 4] != count)
			return (0);
	}
	return (1);
}

int	check_col_down(int *result, int *input, int pos)
{
	int	can_view;
	int	count;
	int	i;

	if (pos / 4 == 3)
	{
		i = 3;
		can_view = 0;
		count = 0;
		while (i >= 0)
		{
			if (result[i * 4 + pos % 4] > can_view)
			{
				can_view = result[i * 4 + pos % 4];
				count++;
			}
			i--;
		}
		if (input[4 + pos % 4] != count)
			return (0);
	}
	return (1);
}

int	check_row_left(int *result, int *input, int pos)
{
	int	can_view;
	int	count;
	int	i;

	if (pos % 4 == 3)
	{
		i = 0;
		can_view = 0;
		count = 0;
		while (i < 4)
		{
			if (result[pos / 4 * 4 + i] > can_view)
			{
				can_view = result[pos / 4 * 4 + i];
				count++;
			}
			i++;
		}
		if (input[8 + pos / 4] != count)
			return (0);
	}
	return (1);
}
