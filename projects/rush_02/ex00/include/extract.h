/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:27:00 by photon            #+#    #+#             */
/*   Updated: 2023/07/09 16:59:43 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRACT_H
# define EXTRACT_H
# include <stdlib.h>
# include "def.h"
# include "reader.h"
# include "utils.h"

int		check_valid(char *start_ptr, char *end_ptr);
int		count_vals(char *dict_buffer);
int		extract_line(char *start_ptr, char *end_ptr, t_uint *key, char **val);
t_nd	*extract_vals(char *dict_buffer, int num_node);
int		load_vals(char *dict_buffer, t_nd **key_list);

#endif
