/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:23:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 15:41:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"

char	*get_dict_value(t_dict *dict, char *key)
{
	char	*dict_key;

	while (dict)
	{
		dict_key = ((t_str_pair *)dict->content)->s1;
		if (!ft_strcmp(dict_key, key))
			return (((t_str_pair *)dict->content)->s2);
		dict = dict->next;
	}
	return (NULL);
}
