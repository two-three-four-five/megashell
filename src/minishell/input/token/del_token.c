/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:38:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/01 14:43:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/parse.h"
#include <stdlib.h>

void	del_token(void *ptr)
{
	if (!ptr)
		return ;
	else if (!((t_token *)ptr)->token)
		free(ptr);
	else
	{
		free(((t_token *)ptr)->token);
		free(ptr);
	}
}
