/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:04:34 by photon            #+#    #+#             */
/*   Updated: 2023/07/05 17:01:54 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	len(char *str)
{
	int	l;

	l = 0;
	while (*str)
	{
		l++;
		str++;
	}
	return (l);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}

char	*ft_strdup(char *src)
{
	char	*new_str;

	new_str = (char *) malloc(len(src) + 1);
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, src);
	return (new_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab_ptr;

	tab_ptr = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab_ptr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab_ptr[i].size = len(av[i]);
		tab_ptr[i].str = av[i];
		tab_ptr[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab_ptr[i].str = 0;
	return (tab_ptr);
}
