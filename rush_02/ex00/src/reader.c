/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:05:39 by photon            #+#    #+#             */
/*   Updated: 2023/07/09 16:52:24 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

int	get_file_size(char *path)
{
	int		fd;
	int		file_size;
	char	tmp_buf[1];

	file_size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, tmp_buf, 1) > 0)
		file_size++;
	if (close(fd) < 0)
		return (-2);
	return (file_size);
}

int	read_dict(char *path, char **dict_buffer)
{
	int	fd;
	int	f_size;

	f_size = get_file_size(path);
	if (f_size <= 0)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-2);
	*dict_buffer = (char *) malloc (sizeof(char) * (f_size + 1));
	if (*dict_buffer == NULL)
		return (-3);
	if (read(fd, *dict_buffer, f_size) < 0)
		return (-4);
	(*dict_buffer)[f_size] = '\0';
	if (close(fd) < 0)
		return (-5);
	return (0);
}
