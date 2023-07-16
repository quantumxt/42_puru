/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:05:39 by photon            #+#    #+#             */
/*   Updated: 2023/07/08 19:58:56 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int	get_file_size(char *path);
int	read_dict(char *path, char **dict_buffer);

#endif