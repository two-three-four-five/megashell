/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_undefined_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:48:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/02 01:52:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"
#include "shell/parse.h"
#include <stdio.h>

t_bool	check_undefined_token(t_list *lst)
{
	t_token	*curr;

	while (lst)
	{
		curr = (t_token *)lst->content;
		if (curr->type == UNDEFINED)
		{
			printf("dish: syntax error undefined operator `%s\'\n", curr->token);
			return (FALSE);
		}
		lst = lst->next;
	}	
	return (TRUE);
}
