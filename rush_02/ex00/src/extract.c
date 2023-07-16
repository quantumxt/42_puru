/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:33:48 by photon            #+#    #+#             */
/*   Updated: 2023/07/09 16:55:17 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extract.h"

int	check_valid(char *start_ptr, char *end_ptr)
{
	int		check_val_region;
	int		check_val_valid;
	t_ull	tmp;

	check_val_region = 0;
	check_val_valid = 0;
	while (*start_ptr && *end_ptr && *start_ptr != *end_ptr)
	{
		start_ptr = space_forward(start_ptr);
		start_ptr = extract_num(start_ptr, &tmp, NULL);
		if (!check_val_region && *start_ptr == ':')
			check_val_region = 1;
		else if (check_val_region && *start_ptr != ' ')
			check_val_valid = 1;
		else if (check_val_region && check_val_valid)
			if (is_non_printable(*start_ptr))
				return (0);
		start_ptr++;
	}
	if (!check_val_region || !check_val_valid)
		return (0);
	return (1);
}

int	count_vals(char *dict_buffer)
{
	int		num_node;
	int		is_valid_val;
	char	*ptr_start;
	char	*ptr_end;

	num_node = 0;
	is_valid_val = 0;
	ptr_start = dict_buffer;
	ptr_end = dict_buffer;
	while (*dict_buffer)
	{
		if (*dict_buffer == '\n')
		{
			is_valid_val = check_valid(ptr_start, ptr_end);
			if (is_valid_val)
				num_node++;
			ptr_start = dict_buffer + 1;
		}
		dict_buffer++;
		ptr_end = dict_buffer;
	}
	return (num_node);
}

int	extract_line(char *start_ptr, char *end_ptr, t_uint *key, char **val)
{
	t_ull	ex_num;

	ex_num = 0;
	start_ptr = space_forward(start_ptr);
	if (is_num(*start_ptr))
	{
		start_ptr = extract_num(start_ptr, &ex_num, NULL);
		*key = (t_uint) ex_num;
	}
	while (*start_ptr != *end_ptr && *start_ptr != ':')
		start_ptr++;
	if (*start_ptr == ':')
		start_ptr++;
	start_ptr = space_forward(start_ptr);
	while (*start_ptr != *end_ptr && !is_non_printable(*start_ptr))
	{
		c_cat(val, *start_ptr);
		start_ptr++;
	}
	return (1);
}

t_nd	*extract_vals(char *dict_buffer, int num_node)
{
	int		i;
	char	*ptr_start;
	char	*ptr_end;
	char	*ex_val;
	t_nd	*key_list;

	i = 0;
	ptr_start = dict_buffer;
	key_list = (t_nd *) malloc(sizeof(t_nd) * (num_node + 1));
	if (!key_list)
		return (NULL);
	while (*dict_buffer)
	{
		if (*dict_buffer == '\n')
		{
			ex_val = (char *) malloc(2 * sizeof(char));
			ex_val[0] = '\0';
			if (extract_line(ptr_start, ptr_end, &key_list[i].key, &ex_val))
				key_list[i++].val = ft_strdup(ex_val);
			ptr_start = dict_buffer + 1;
			free(ex_val);
		}
		ptr_end = ++dict_buffer;
	}
	return (key_list);
}

int	load_vals(char *dict_buffer, t_nd **key_list)
{
	int		num_node;

	num_node = count_vals(dict_buffer);
	if (num_node < 1)
		return (-1);
	*key_list = extract_vals(dict_buffer, num_node);
	return (0);
}
