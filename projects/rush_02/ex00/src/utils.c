/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:34:03 by photon            #+#    #+#             */
/*   Updated: 2023/07/09 16:48:32 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*space_forward(char *str)
{
	while (*str && is_space(*str))
		str++;
	return (str);
}

char	*extract_num(char *str, t_ull *arg_val, int *num_start)
{
	while (*str && is_num(*str))
	{
		if (num_start != NULL)
			*num_start = 1;
		*arg_val = 10 * (*arg_val) + (*str - '0');
		str++;
	}
	return (str);
}

void	c_cat(char **dest, char src)
{
	char	*temp;

	temp = *dest;
	while (*temp)
		temp++;
	*temp = src;
	temp++;
	*temp = '\0';
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
	char	*len_check;
	int		str_len;

	str_len = 0;
	len_check = src;
	while (*len_check)
	{
		str_len++;
		len_check++;
	}
	new_str = (char *) malloc(str_len + 1);
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, src);
	return (new_str);
}
