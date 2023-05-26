/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_str_pair_s1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:42:22 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/23 15:10:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type/str_pair.h"

void	*dup_str_pair_s1(void *ptr)
{
	char		*ret;
	t_str_pair	*str_pair;

	str_pair = ptr;
	if (!ptr)
		return (NULL);
	ret = ft_strdup(str_pair->s1);
	return (ret);
}
