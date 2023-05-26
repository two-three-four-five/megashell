/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_str_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:26:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 17:49:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "type.h"

static void	*del_strs(char *s1, char *s2);

t_str_pair	*new_str_pair(char *s1, char *s2)
{
	t_str_pair	*pair;

	pair = (t_str_pair *)ft_calloc(1, sizeof(t_str_pair));
	if (!pair)
		return (del_strs(s1, s2));
	pair->s1 = s1;
	pair->s2 = s2;
	return (pair);
}

static void	*del_strs(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}
