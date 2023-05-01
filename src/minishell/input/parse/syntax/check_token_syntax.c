/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:54:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/02 01:36:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdio.h>

// static t_bool	check_undefined(t_token *curr)
// {
// 	if (curr->type == UNDEFINED)
// 	{
// 		printf("dish: syntax error undefined operator `%s\'\n", curr->token);
// 		return (FALSE);
// 	}
// 	else
// 		return (TRUE);
// }

static t_bool	check_word(char prev, char curr);
static t_bool	check_newline(char prev, char curr);
static t_bool	check_logical(char prev, char curr);
static t_bool	check_redirection(char prev, char curr);
static t_bool	check_parentheses(char prev, char curr);
t_bool			check_operator_syntax(t_list *lst);

t_bool	check_token_syntax(t_list *lst)
{
	char	prev;
	char	curr;

	prev = UNDEFINED;
	while (lst)
	{
		curr = ((t_token *)lst->content)->type;
		if (!check_word(prev, curr) || \
			!check_newline(prev, curr) || \
			!check_logical(prev, curr) || \
			!check_redirection(prev, curr) || \
			!check_parentheses(prev, curr))
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

static t_bool	check_word(char prev, char curr)
{
	if ((curr == WORD) && \
		(prev == NEWLINE || prev == CLOSE_PAREN))
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	check_newline(char prev, char curr)
{
	if ((curr == NEWLINE) && \
		(prev == PIPE || prev & LOGIC || prev & REDIRECT || prev == OPEN_PAREN))
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	check_logical(char prev, char curr)
{
	if ((curr == PIPE || curr == AND_IF || curr == OR_IF) && \
		(prev == PIPE || prev == NEWLINE || prev & LOGIC || \
			prev & REDIRECT || prev == OPEN_PAREN || prev == UNDEFINED))
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	check_redirection(char prev, char curr)
{
	if ((curr & REDIRECT) && \
		(prev == PIPE || prev == NEWLINE || prev & LOGIC || prev & REDIRECT))
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	check_parentheses(char prev, char curr)
{
	if ((curr == OPEN_PAREN) && \
		(prev == WORD || prev == NEWLINE || \
			prev & REDIRECT || prev == CLOSE_PAREN))
		return (FALSE);
	else if ((curr == CLOSE_PAREN) && \
			(prev == PIPE || prev == NEWLINE || prev & LOGIC || \
				prev & REDIRECT || prev == OPEN_PAREN || prev == UNDEFINED))
		return (FALSE);
	else
		return (TRUE);
}
