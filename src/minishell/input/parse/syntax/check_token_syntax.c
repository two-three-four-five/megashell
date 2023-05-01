/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:54:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/02 01:47:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdio.h>

static t_bool	check_word_syntax(char prev, char curr);
static t_bool	check_newline_syntax(char prev, char curr);
static t_bool	check_operator_syntax(char prev, char curr);
t_bool			check_token_syntax(t_list *lst);

t_bool	check_token_syntax(t_list *lst)
{
	char	prev;
	char	curr;

	prev = UNDEFINED;
	while (lst)
	{
		curr = ((t_token *)lst->content)->type;
		if (!check_word_syntax(prev, curr) || \
			!check_newline_syntax(prev, curr) || \
			!check_operator_syntax(prev, curr))
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

static t_bool	check_word_syntax(char prev, char curr)
{
	if ((curr == WORD) && \
		(prev == NEWLINE || prev == CLOSE_PAREN))
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	check_newline_syntax(char prev, char curr)
{
	if ((curr == NEWLINE) && \
		(prev == PIPE || prev & LOGIC || prev & REDIRECT || prev == OPEN_PAREN))
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	check_operator_syntax(char prev, char curr)
{
	if ((curr == PIPE || curr == AND_IF || curr == OR_IF) && \
		(prev == PIPE || prev == NEWLINE || prev & LOGIC || \
			prev & REDIRECT || prev == OPEN_PAREN || prev == UNDEFINED))
		return (FALSE);
	else if ((curr & REDIRECT) && \
		(prev == PIPE || prev == NEWLINE || prev & LOGIC || prev & REDIRECT))
		return (FALSE);
	else if ((curr == OPEN_PAREN) && \
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
