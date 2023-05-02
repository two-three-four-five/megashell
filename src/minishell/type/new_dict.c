/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:26:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/02 16:33:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include <stdlib.h>

static void	*del_char_pointers(char *s1, char *s2);

t_dict	*new_dict(char *key, char *value)
{
	t_dict	*dict;

	if (!key || !value)
		return (del_char_pointers(key, value));
	dict = (t_dict *)ft_calloc(1, sizeof(t_dict));
	if (!dict)
		return (del_char_pointers(key, value));
	dict->key = key;
	dict->value = value;
	return (dict);
}

static void	*del_char_pointers(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}
