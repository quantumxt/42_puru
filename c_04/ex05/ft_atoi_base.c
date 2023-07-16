/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 21:52:58 by photon            #+#    #+#             */
/*   Updated: 2023/07/07 16:19:55 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

int	valid_base(char *str)
{
	int		str_count;
	int		dup_check;

	str_count = 0;
	while (str[str_count])
	{
		if (str[str_count] == '+' || str[str_count] == '-')
			return (-1);
		dup_check = 0;
		while (dup_check < str_count)
		{
			if (str[str_count] == str[dup_check])
				return (-1);
			dup_check++;
		}
		str_count++;
	}
	return (str_count);
}

int	check_space(char str)
{
	return ((str >= 9 && str <= 13) || str == ' ');
}

int	extract_val(char *str, char *charmap, int num_base, int num_base_len)
{
	char	*base_ptr;
	long	ret_val;
	int		idx;

	ret_val = 0;
	while (*str)
	{
		base_ptr = charmap;
		idx = 0;
		while (*base_ptr && *str != *base_ptr)
		{
			idx++;
			base_ptr++;
		}
		if (idx > num_base_len)
			return (0);
		ret_val = num_base * ret_val + idx;
		str++;
	}
	return ((int) ret_val);
}

int	ft_atoi_base(char *str, char *base)
{
	int	neg_val;
	int	num_base;

	num_base = valid_base(base);
	if (num_base < 2)
		return (0);
	neg_val = 1;
	while (*str && check_space(*str))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			neg_val *= -1;
		str++;
	}
	return (neg_val * extract_val(str, base, num_base, len(base)));
}
/*
#include <stdio.h>
int	main(void) {
	// expected: 0 (invalid as spaces between numbers and signs)
	printf("%d\n", ft_atoi_base("   -- -+--+12 34ab567", "0123456789abcdef"));
	// expected: 0 (invalid as spaces between signs and numbers)
	printf("%d\n", ft_atoi_base("  + 42", "0123456789"));
	// expected: 0 (invalid as spaces between signs and numbers)
	printf("%d\n", ft_atoi_base("- 1", "01"));
	// expected: 0 (invalid as spaces between numbers and signs)
	printf("%d\n", ft_atoi_base("   + ++101 0", "01"));
	// expected: 7 (invalid as spaces between numbers)
	printf("%d\n", ft_atoi_base("7a 9", "0123456789abcdef"));
	// expected: 1953 (stops at space before 'g')
	printf("%d\n", ft_atoi_base("7a9 g", "0123456789abcdef"));
	// expected: 0 (invalid base)
	printf("%d\n", ft_atoi_base("  - 42", "0"));
	// expected: 0 (invalid base)
	printf("%d\n", ft_atoi_base("4 2", "0"));
	// expected: 0 (invalid base)
	printf("$$ %d\n", ft_atoi_base("10 1", "02350"));
	// expected: 0 (invalid base)
	printf("%d\n", ft_atoi_base("  + 42", "0123456789+"));
	// expected: 0 (invalid base)
	printf("%d\n", ft_atoi_base("  - 42", "0123456789-"));
	// expected: 1256 (space is the additional char)
	printf("%d\n", ft_atoi_base("  + 42", "0123456789 "));
	// expected: 0 (invalid base)
	printf("%d\n", ft_atoi_base("  + 42", "01234567899"));
	// expected: 2147483647
	printf(">> %d\n", ft_atoi_base("2147483647", "0123456789"));
	// expected: -2147483648
	printf(">> %d\n", ft_atoi_base("-2147483648", "0123456789"));
	return (0);
}
*/
