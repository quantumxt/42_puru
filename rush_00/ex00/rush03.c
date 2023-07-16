/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:17:47 by photon            #+#    #+#             */
/*   Updated: 2023/06/25 15:31:24 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int l, char a, char b, char c)
{
	int	pos_x;

	ft_putchar(a);
	pos_x = 0;
	while (pos_x < (l - 2))
	{
		ft_putchar(b);
		pos_x++;
	}
	if (l > 1)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush03(int x, int y)
{
	int	height;

	if (x > 0 && y > 0)
	{
		print_line(x, 'A', 'B', 'C');
		height = 0;
		if (y > 1)
		{
			while (height < (y - 2))
			{
				print_line(x, 'B', ' ', 'B');
				height++;
			}
			print_line(x, 'A', 'B', 'C');
		}
	}
}
