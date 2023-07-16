/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:09:14 by photon            #+#    #+#             */
/*   Updated: 2023/06/24 21:04:49 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_range(char st)
{
	return ((st >= 'A' && st <= 'Z') || (st >= 'a' && st <= 'z'));
}

int	ft_str_is_alpha(char *str)
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
	char *b = "ghi99hs";
	char *c = "jdsh hjs oo";
	printf("> %s, is_alpha: %i\n", a, ft_str_is_alpha(a));
	printf("> %s, is_alpha: %i\n", b, ft_str_is_alpha(b));
	printf("> %s, is_alpha: %i\n", c, ft_str_is_alpha(c));
	return 0;
}
*/
