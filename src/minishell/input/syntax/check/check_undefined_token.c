/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_undefined_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:48:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/15 20:40:32 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"
#include "shell/parse.h"
#include "shell/error.h"

t_bool	check_undefined_token(t_list *lst)
{
	t_token	*curr;

	while (lst)
	{
		curr = (t_token *)lst->content;
		if (curr->type == UNDEFINED)
		{
			raise_syntax_error(UNDEFINED_TOKEN, curr->token, 0, 0);
			return (FALSE);
		}
		lst = lst->next;
	}	
	return (TRUE);
}
