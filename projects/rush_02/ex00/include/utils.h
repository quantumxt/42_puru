/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:27:30 by photon            #+#    #+#             */
/*   Updated: 2023/07/09 16:58:41 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "stdlib.h"
# include "def.h"
# include "check.h"

char	*space_forward(char *str);
char	*extract_num(char *str, t_ull *arg_val, int *num_start);
void	c_cat(char **dest, char src);
void	ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);

#endif
