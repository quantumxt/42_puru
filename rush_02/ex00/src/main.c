/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: photon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:55:57 by photon            #+#    #+#             */
/*   Updated: 2023/07/09 16:58:01 by photon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	extraction(char	*arg_val, char *dict_path, t_nd	**val_list)
{
	char	*dict_buf;
	t_uint	extracted_num;

	extracted_num = 0;
	if (atoui(arg_val, &extracted_num) != 0)
		return (-1);
	if (read_dict(dict_path, &dict_buf) != 0)
	{
		free(dict_buf);
		return (-2);
	}
	load_vals(dict_buf, val_list);
	num_to_text(extracted_num, val_list);
	prt("\n", 0);
	return (0);
}

int	free_me(t_nd **val_list)
{
	int	i;

	i = 0;
	while (val_list[i])
	{
		free(val_list[i]->val);
		free(val_list[i]);
		i++;
	}
	free(val_list);
	return (0);
}

int	main(int argc, char **argv)
{
	int		ret_stat;
	t_nd	**val_list;

	ret_stat = 0;
	val_list = (t_nd **) malloc(sizeof(t_nd *));
	if (argc == 2)
		ret_stat = extraction(argv[1], "numbers.dict", val_list);
	else if (argc == 3)
		ret_stat = extraction(argv[2], argv[1], val_list);
	else
	{
		prt("Error", 1);
		return (0);
	}
	if (ret_stat == -1)
		return (err(0));
	if (ret_stat == -2)
		return (err(1));
	free_me(val_list);
	return (0);
}
