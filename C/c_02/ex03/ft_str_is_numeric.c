/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:09:14 by photon            #+#    #+#             */
/*   Updated: 2023/06/24 21:09:51 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_range(char st)
{
	return (st >= '0' && st <= '9');
}

int	ft_str_is_numeric(char *str)
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
	char *a = "1618";
	char *b = "ghi99hs";
	char *c = "3.14159";
	printf("> %s, is_num: %i\n", a, ft_str_is_numeric(a));
	printf("> %s, is_num: %i\n", b, ft_str_is_numeric(b));
	printf("> %s, is_num: %i\n", c, ft_str_is_numeric(c));
	return 0;
}
*/
