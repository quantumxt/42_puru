/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:05:39 by photon            #+#    #+#             */
/*   Updated: 2023/07/09 17:15:25 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H
# include "def.h"
# include "utils.h"
# include "display.h"

int		atoui(char *str, t_uint *res_out);
char	*lookup(t_nd *dict, t_uint key);
void	multiple_check(t_uint *num, t_uint target, t_nd **val_list);
int		num_to_text(t_uint num, t_nd **val_list);

#endif
