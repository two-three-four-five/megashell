/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:54:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/01 20:19:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdio.h>

static t_bool	check_undefined(t_token *curr);
static t_bool	check_logical(t_token *pre, t_token *curr, t_token *next);
static t_bool	check_redirection(t_token *curr, t_token *next);
t_bool			check_operator_syntax(t_list *lst);

t_bool	check_operator_syntax(t_list *lst)
{
	t_token	*pre;
	t_token	*curr;
	t_token	*next;

	pre = NULL;
	next = NULL;
	while (lst)
	{
		curr = ((t_token *)lst->content);
		if (lst->next)
			next = (t_token *)lst->next->content;
		else
			next = NULL;
		if (!check_undefined(curr))
			return (FALSE);
		else if (!check_logical(pre, curr, next))
			return (FALSE);
		else if (!check_redirection(curr, next))
			return (FALSE);
		pre = curr;
		lst = lst->next;
	}
	return (TRUE);
}

static t_bool	check_undefined(t_token *curr)
{
	if (curr->type == UNDEFINED)
	{
		printf("dish: syntax error undefined operator `%s\'\n", curr->token);
		return (FALSE);
	}
	else
		return (TRUE);
}

static t_bool	check_logical(t_token *pre, t_token *curr, t_token *next)
{
	if (curr->type == PIPE || curr->type == AND_IF || curr->type == OR_IF)
	{
		if ((pre && next) && \
			((pre->type == CLOSE_PAREN || pre->type == WORD) && \
			(next->type == OPEN_PAREN || next->type == WORD || \
			next->type & REDIRECT)))
			return (TRUE);
		else
		{
			printf("dish: syntax error near unexpected token `%s\'\n", \
					curr->token);
			return (FALSE);
		}
	}
	return (TRUE);
}

static t_bool	check_redirection(t_token *curr, t_token *next)
{
	if (curr->type & REDIRECT && (next && next->type != WORD))
	{
		printf("dish: syntax error near unexpected token `%s\'\n", \
				next->token);
		return (FALSE);
	}
	return (TRUE);
}
