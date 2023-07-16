/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:12:51 by photon            #+#    #+#             */
/*   Updated: 2023/07/04 12:47:36 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new_str;
	int		str_len;
	int		i;

	str_len = 0;
	i = -1;
	while (src[++i])
		str_len++;
	new_str = (char *) malloc(str_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (src[++i])
		new_str[i] = src[i];
	new_str[i] = '\0';
	return (new_str);
}
