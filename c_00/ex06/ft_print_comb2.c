/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:52:37 by photon            #+#    #+#             */
/*   Updated: 2023/06/26 13:58:35 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int a)
{
	char	*char_map;
	char	num[3];

	char_map = "0123456789";
	num[0] = char_map[a / 10];
	num[1] = char_map[a % 10];
	num[2] = '\0';
	write(1, num, 2);
}

void	print_lines(int first, int second)
{
	print_num(first);
	write(1, " ", 1);
	print_num(second);
	if (!(first == 98 && second == 99))
		write(1, ", ", 2);
}

void	set_num(int a, int b, int *idx_list)
{
	idx_list[0] = a;
	idx_list[1] = b;
}

void	ft_print_comb2(void)
{
	int	idx[2];

	set_num(0, 1, idx);
	while (idx[0] <= 97)
	{	
		set_num(idx[0], idx[0] + 1, idx);
		while (idx[1] <= 99)
		{
			print_lines(idx[0], idx[1]);
			idx[1]++;
		}
		set_num(++idx[0], 0, idx);
	}
	print_lines(idx[0], idx[0] + 1);
}
/*
int	main(void)
{
	ft_print_comb2();
	return 0;
}
*/
