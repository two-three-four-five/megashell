/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_str_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:34:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 14:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include <stdlib.h>

void	del_str_pair(void *ptr)
{
	if (!ptr)
		return ;
	if (((t_str_pair *)ptr)->s1)
		free(((t_str_pair *)ptr)->s1);
	if (((t_str_pair *)ptr)->s2)
		free(((t_str_pair *)ptr)->s2);
	free(ptr);
}
