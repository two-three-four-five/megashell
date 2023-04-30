/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:23:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/30 16:46:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <shell/type.h>
#include <stdio.h>

static char	*get_unmatched_parenthesis(t_list *lst)
{
	char	parenthesis;
	char	*str;

	parenthesis = 0;
	while (lst)
	{
		str = (char *)lst->content;
		while (*str)
		{
			if (*str == '(')
				parenthesis++;
			else if (*str == ')')
				parenthesis--;
			str++;
		}
		lst = lst->next;
	}
	if (parenthesis < 0)
		return (")");
	else if (parenthesis > 0)
		return ("(");
	else
		return (NULL);
}

t_bool	check_parenthesis(t_list *lst)
{
	char	*token;

	token = get_unmatched_parenthesis(lst);
	if (token)
	{
		printf("dish: syntax error near unexpected token `%s\'\n", token);
		return (FALSE);
	}
	else
		return (TRUE);
}
