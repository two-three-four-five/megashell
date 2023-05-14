/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:54:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 22:59:18 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdio.h>

t_bool	check_token_order(t_list *lst)
{
	char	prev;
	char	curr;

	prev = UNDEFINED;
	while (lst)
	{
		curr = ((t_token *)lst->content)->type;
		if (!check_word_order(prev, curr) || \
			!check_newline_order(prev, curr) || \
			!check_operator_order(prev, curr))
		{
			if (curr == NEWLINE)
				printf("dish: syntax error near unexpected token `%s\'\n", \
						"newline");
			else
				printf("dish: syntax error near unexpected token `%s\'\n", \
					((t_token *)lst->content)->token);
			return (FALSE);
		}
		prev = curr;
		lst = lst->next;
	}
	return (TRUE);
}
