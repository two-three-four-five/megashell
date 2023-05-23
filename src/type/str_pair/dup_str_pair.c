/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_str_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:24:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/23 15:11:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type/str_pair.h"

void	*dup_str_pair(void *ptr)
{
	t_str_pair	*ret;
	t_str_pair	*original;

	original = ptr;
	if (!ptr)
		return (NULL);
	ret = new_str_pair(ft_strdup(original->s1), ft_strdup(original->s2));
	return (ret);
}
