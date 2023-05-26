/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:38:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 15:51:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell/input.h"

void	del_token(void *ptr)
{
	if (!ptr)
		return ;
	else if (((t_token *)ptr)->token)
		free(((t_token *)ptr)->token);
	free(ptr);
}
