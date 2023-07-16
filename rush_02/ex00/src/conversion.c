/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:05:39 by photon            #+#    #+#             */
/*   Updated: 2023/07/09 16:44:53 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

int	atoui(char *str, t_uint *res_out)
{
	t_ull	arg_val;
	int		num_start;

	arg_val = 0;
	num_start = 0;
	str = space_forward(str);
	if (*str && is_sign(*str))
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	str = extract_num(str, &arg_val, &num_start);
	if (!num_start || arg_val > UNSIGNED_MAX)
		return (-2);
	*res_out = (t_uint) arg_val;
	return (0);
}

char	*lookup(t_nd *dict, t_uint key)
{
	int	i;

	i = 0;
	while ((dict + i)->val)
	{
		if (dict[i].key == key)
			return (dict[i].val);
		i++;
	}
	return (NULL);
}

void	multiple_check(t_uint *num, t_uint target, t_nd **val_list)
{
	if (*num >= target)
	{
		num_to_text(*num / target, val_list);
		prt(lookup(*val_list, target), 0);
		*num %= target;
		if (*num > 0)
			prt(" ", 0);
	}
}

int	num_to_text(t_uint num, t_nd **val_list)
{
	if (num == 0)
	{
		prt(lookup(*val_list, num), 0);
		return (1);
	}
	multiple_check(&num, 1000000000, val_list);
	multiple_check(&num, 1000000, val_list);
	multiple_check(&num, 1000, val_list);
	multiple_check(&num, 100, val_list);
	if (num >= 20)
	{
		prt(lookup(*val_list, (num / 10) * 10), 3);
		num %= 10;
	}
	if (num > 0)
		prt(lookup(*val_list, num), 3);
	return (-1);
}
