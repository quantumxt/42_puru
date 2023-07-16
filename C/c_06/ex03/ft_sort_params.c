/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:58:28 by photon            #+#    #+#             */
/*   Updated: 2023/06/29 20:58:30 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	check_args(int loop_left, char *argv[])
{
	int		i;
	char	*tmp_arg;

	i = 0;
	while (loop_left > 0)
	{
		i = 1;
		while (i < loop_left - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tmp_arg = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp_arg;
			}
			i++;
		}
		loop_left--;
	}
}

int	main(int argc, char *argv[])
{
	int	pos;

	if (argc > 2)
		check_args(argc, argv);
	pos = 1;
	while (pos < argc)
		print_str(argv[pos++]);
	return (0);
}
