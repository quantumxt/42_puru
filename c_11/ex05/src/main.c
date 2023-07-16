/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:03:40 by photon            #+#    #+#             */
/*   Updated: 2023/07/13 15:10:40 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ops.h"
#include "check.h"
#include "display.h"

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

int	div_zero_err(char c, int b)
{
	if (c == '/' && b == 0)
	{
		prt("Stop : division by zero");
		return (1);
	}
	if (c == '%' && b == 0)
	{
		prt("Stop : modulo by zero");
		return (1);
	}
	return (0);
}

int	sel_op(int a, int b, char op)
{
	int	res;

	res = 0;
	if (op == '+')
		res = add(a, b);
	else if (op == '-')
		res = subtract(a, b);
	else if (op == '*')
		res = multiply(a, b);
	else if (op == '/')
		res = division(a, b);
	else if (op == '%')
		res = modulo(a, b);
	return (res);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	opr;

	if (argc == 4)
	{
		opr = argv[2][0];
		if (!check_operator(opr))
			prt("0");
		else
		{
			a = ft_atoi(argv[1]);
			b = ft_atoi(argv[3]);
			if (!div_zero_err(opr, b))
				print_num(sel_op(a, b, opr));
		}
		prt("\n");
	}
	return (0);
}
