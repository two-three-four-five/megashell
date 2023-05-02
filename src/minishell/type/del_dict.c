/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:34:05 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/02 17:09:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"
#include <stdlib.h>

void	del_dict(void *ptr)
{
	if (!ptr)
		return ;
	if (((t_dict *)ptr)->key)
		free(((t_dict *)ptr)->key);
	if (((t_dict *)ptr)->value)
		free(((t_dict *)ptr)->value);
	free(ptr);
}
