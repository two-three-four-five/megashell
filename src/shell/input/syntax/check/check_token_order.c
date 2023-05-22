/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:54:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 14:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/parse.h"
#include "shell/error.h"

static t_bool	check_order(t_list *lst);
static t_bool	check_order_without_redirect(t_list *lst);
t_bool			check_token_order(t_list *lst);

t_bool	check_token_order(t_list *lst)
{
	if (check_order(lst) && check_order_without_redirect(lst))
		return (TRUE);
	else
		return (FALSE);
}

static t_bool	check_order(t_list *lst)
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
				raise_syntax_error(UNEXPECTED_TOKEN, "newline", 0, 0);
			else
				raise_syntax_error(UNEXPECTED_TOKEN, \
					((t_token *)lst->content)->token, 0, 0);
			return (FALSE);
		}
		prev = curr;
		lst = lst->next;
	}
	return (TRUE);
}

static t_bool	check_order_without_redirect(t_list *lst)
{
	char	prev;

	prev = UNDEFINED;
	while (lst)
	{
		if (((t_token *)lst->content)->type == REDIRECT)
		{
			lst = lst->next->next;
			continue ;
		}
		if (!check_word_order(prev, ((t_token *)lst->content)->type) || \
			!check_newline_order(prev, ((t_token *)lst->content)->type) || \
			!check_operator_order(prev, ((t_token *)lst->content)->type))
		{
			if (((t_token *)lst->content)->type == NEWLINE)
				raise_syntax_error(UNEXPECTED_TOKEN, "newline", 0, 0);
			else
				raise_syntax_error(UNEXPECTED_TOKEN, \
					((t_token *)lst->content)->token, 0, 0);
			return (FALSE);
		}
		prev = ((t_token *)lst->content)->type;
		lst = lst->next;
	}
	return (TRUE);
}
