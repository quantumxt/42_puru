/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:05:39 by photon            #+#    #+#             */
/*   Updated: 2023/07/09 17:22:13 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H
# define UNSIGNED_MAX 4294967295

typedef unsigned long long	t_ull;
typedef unsigned int		t_uint;

typedef struct s_node
{
	t_uint	key;
	char	*val;
}	t_nd;

#endif
