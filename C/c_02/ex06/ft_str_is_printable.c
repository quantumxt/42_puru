/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:09:14 by photon            #+#    #+#             */
/*   Updated: 2023/06/24 21:22:11 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_range(char st)
{
	return (st >= ' ' && st <= '~');
}

int	ft_str_is_printable(char *str)
{
	int	is_valid;

	is_valid = 1;
	while (*str)
	{
		is_valid = check_range(*str);
		if (!is_valid)
			return (is_valid);
		str++;
	}
	return (is_valid);
}
/*
#include <stdio.h>
int main(){
	char *a = "AB_88fg";
	char *b = "\t\n";
	printf("> %s, is_printable: %i\n", a, ft_str_is_printable(a));
	printf("> %s, is_printable: %i\n", b, ft_str_is_printable(b));
	return 0;
}
*/
