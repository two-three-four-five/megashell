/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:23:01 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/06 17:48:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"

char	*get_dict_value(t_dict *dict, char *key)
{
	char	*dict_key;

	while (dict)
	{
		dict_key = ((t_str_pair *)dict->content)->s1;
		if (!ft_strncmp(dict_key, key, ft_strlen(dict_key)))
			return (((t_str_pair *)dict->content)->s2);
		dict = dict->next;
	}
	return (NULL);
}
