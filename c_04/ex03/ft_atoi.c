/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:51:49 by photon            #+#    #+#             */
/*   Updated: 2023/07/03 21:09:45 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_space(char str)
{
	return ((str >= 9 && str <= 13) || str == ' ');
}

int	ft_atoi(char *str)
{
	int	neg_val;
	int	ret_val;

	ret_val = 0;
	neg_val = 1;
	while (*str && check_space(*str))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			neg_val *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		ret_val = 10 * ret_val + (*str - '0');
		str++;
	}
	return (neg_val * ret_val);
}
/*
#include <assert.h>
void	run_test(char *src, int expected)
{
	int res = ft_atoi(src);
	printf("\nSrc: %s\nResult: %d\n", src, res);
	assert(res == expected);
}

int	main()
{
	// Expects -1234
	run_test("   -1234", -1234);
	// Expects 1234
	run_test("  ---+--+1234ab567", -1234);
	// Expects 314
	run_test("+++++314", 314);
	// Expects -12
	run_test("--+-+--12", -12);
	// Expects nothing
	run_test("abc124", 0);
	// Expects 0, stops at spaces
	run_test("   ++++++++   567", 0);
	// Expects 0, no numbers
	run_test("   ", 0);
	// Expects 55, space before number
	run_test("\t  55", 55);
	// Expects -1234, stops at non-digit 'f'
	run_test("-+--+-+-+--741foo123", -741);
	// Expects 2147483647 (INT_MAX)
	run_test("2147483647", 2147483647);
	// Expects -2147483648 (INT_MIN)
	run_test("-2147483648dd", -2147483648);
	
	printf("\n~~~~ Passed all tests! ~~~~\n");

	return 0;
}
*/
