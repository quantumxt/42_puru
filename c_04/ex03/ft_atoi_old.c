/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:51:49 by photon            #+#    #+#             */
/*   Updated: 2023/06/29 14:23:46 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_range(char st)
{
	return (st >= '0' && st <= '9');
}

int	base_pow(int n)
{
	int	val;

	val = 1;
	while (n-- > 0)
		val *= 10;
	return (val);
}

void	process_range(int num_start, int idx, int is_str_end, int *num_range)
{
	if (!num_start)
		num_range[2] = -1;
	else if (is_str_end)
		num_range[1] = idx;
	if (num_start)
		num_range[2] = num_range[1] - num_range[0] - 1;
}

void	extract_num(int *num_range, int *count_neg, char *str)
{
	int	idx;
	int	num_start;

	num_start = 0;
	idx = 0;
	while (str[idx])
	{
		if (!num_start && check_range(str[idx]))
		{
			num_start = 1;
			num_range[0] = idx;
		}
		else if (num_start && !check_range(str[idx]))
		{
			num_range[1] = idx;
			break ;
		}
		else if (str[idx] == '-')
			*count_neg *= -1;
		idx++;
	}
	process_range(num_start, idx, !str[idx], num_range);
}

int	ft_atoi(char *str)
{
	int	num_range[3];
	int	count_neg;
	int	ret_val;
	int	i;

	i = 0;
	count_neg = 1;
	ret_val = 0;
	extract_num(num_range, &count_neg, str);
	while (i <= num_range[2])
	{
		ret_val += base_pow(num_range[2] - i) * (str[num_range[0] + i] - '0');
		i++;
	}
	return (count_neg * ret_val);
}
/*
#include <stdio.h>
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
	// Expects 567, stops at spaces
	run_test("   ++++++++   567", 567);
	// Expects 0, no numbers
	run_test("   ", 0);
	// Expects -1234, stops at non-digit 'f'
	run_test("-+--+-+-+--741foo123", -741);
	// Expects 2147483647 (INT_MAX)
	run_test("a2147483647", 2147483647);
	// Expects -2147483648 (INT_MIN)
	run_test("-2147483648dd", -2147483648);
	
	printf("\n~~~~ Passed all tests! ~~~~\n");

	return 0;
}
*/
