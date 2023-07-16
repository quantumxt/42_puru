/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:05:39 by photon            #+#    #+#             */
/*   Updated: 2023/07/09 16:38:27 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	prt(char *str, int sep_type)
{
	if (str)
	{
		if (sep_type == 2)
			write(1, " ", 1);
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
		if (sep_type == 1)
			write(1, "\n", 1);
		else if (sep_type == 3)
			write(1, " ", 1);
	}
}

int	err(int is_dict_err)
{
	if (is_dict_err)
		prt("Dict Error", 1);
	else
		prt("Error", 1);
	return (0);
}
