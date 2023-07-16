/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:09:14 by photon            #+#    #+#             */
/*   Updated: 2023/06/24 21:17:30 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_range(char st)
{
	return (st >= 'A' && st <= 'Z');
}

int	ft_str_is_uppercase(char *str)
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
	char *a = "ABCDEFG";
	char *b = "ghiFXs";
	char *c = "JSHD hjs oo";
	printf("> %s, is_upper: %i\n", a, ft_str_is_uppercase(a));
	printf("> %s, is_upper: %i\n", b, ft_str_is_uppercase(b));
	printf("> %s, is_upper: %i\n", c, ft_str_is_uppercase(c));
	return 0;
}
*/
