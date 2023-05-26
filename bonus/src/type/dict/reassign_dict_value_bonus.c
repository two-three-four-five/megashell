/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reassign_dict_value_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:31:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "type_bonus.h"

t_bool	reassign_dict_value(t_dict *dict, char *key, char *value)
{
	t_dict	*curr;

	curr = dict;
	while (curr)
	{
		if (!ft_strcmp(((t_str_pair *)curr->content)->s1, key))
		{
			if (((t_str_pair *)curr->content)->s2)
				free(((t_str_pair *)curr->content)->s2);
			((t_str_pair *)curr->content)->s2 = value;
			return (TRUE);
		}
		curr = curr->next;
	}
	return (FALSE);
}
