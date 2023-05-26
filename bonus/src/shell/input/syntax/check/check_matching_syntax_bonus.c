/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matching_syntax_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:07:45 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type_bonus.h"
#include "shell/input_bonus.h"
#include "shell/error_bonus.h"

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
			raise_syntax_error(MISSING_TOKEN, NULL, quote, quote);
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
		raise_syntax_error(UNEXPECTED_TOKEN, ")", 0, 0);
		return (FALSE);
	}
	else if (parenthesis > 0)
	{
		raise_syntax_error(MISSING_TOKEN, NULL, '(', ')');
		return (FALSE);
	}
	return (TRUE);
}
