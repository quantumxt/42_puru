/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:09:14 by photon            #+#    #+#             */
/*   Updated: 2023/06/24 21:14:06 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_range(char st)
{
	return (st >= 'a' && st <= 'z');
}

int	ft_str_is_lowercase(char *str)
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
	char *a = "abcdef";
	char *b = "ghiFXs";
	char *c = "jdsh hjs oo";
	printf("> %s, is_lower: %i\n", a, ft_str_is_lowercase(a));
	printf("> %s, is_lower: %i\n", b, ft_str_is_lowercase(b));
	printf("> %s, is_lower: %i\n", c, ft_str_is_lowercase(c));
	return 0;
}
*/
