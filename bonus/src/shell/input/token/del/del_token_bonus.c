/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:38:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell/input_bonus.h"

void	del_token(void *ptr)
{
	if (!ptr)
		return ;
	else if (((t_token *)ptr)->token)
		free(((t_token *)ptr)->token);
	free(ptr);
}
