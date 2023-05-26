/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_undefined_token_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:48:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"
#include "shell/input_bonus.h"
#include "shell/error_bonus.h"

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
