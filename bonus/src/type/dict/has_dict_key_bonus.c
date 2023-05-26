/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dict_key_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:49:43 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"

t_bool	has_dict_key(t_dict *dict, char *key)
{
	char	*dict_key;

	while (dict)
	{
		dict_key = ((t_str_pair *)dict->content)->s1;
		if (!ft_strcmp(dict_key, key))
			return (TRUE);
		dict = dict->next;
	}
	return (FALSE);
}
