/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matching_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:07:45 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 22:57:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdio.h>

static t_bool	check_quote(t_list *lst);
static t_bool	check_parenthesis(t_list *lst);
t_bool			check_matching_syntax(t_list *lst);

t_bool	check_matching_syntax(t_list *lst)
{
	if (!check_quote(lst) || !check_parenthesis(lst))
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	check_quote(t_list *lst)
{
	char	quote;
	char	*str;

	while (lst)
	{
		quote = 0;
		str = ((t_token *)lst->content)->token;
		while (*str)
		{
			if (!quote && isquote(*str))
				quote = *str;
			else if (quote && *str == quote)
				quote = 0;
			str++;
		}
		if (quote)
		{
			printf("dish: %c: missing `%c\'\n", quote, quote);
			return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}

static t_bool	check_parenthesis(t_list *lst)
{
	char	parenthesis;
	t_token	*token;

	parenthesis = 0;
	while (lst)
	{
		token = (t_token *)lst->content;
		if (token->type == OPEN_PAREN)
			parenthesis++;
		else if (token->type == CLOSE_PAREN)
			parenthesis--;
		lst = lst->next;
	}
	if (parenthesis < 0)
	{
		printf("dish: syntax error near unexpected token `%c\'\n", ')');
		return (FALSE);
	}
	else if (parenthesis > 0)
	{
		printf("dish: %c: missing `%c\'\n", '(', ')');
		return (FALSE);
	}
	return (TRUE);
}
