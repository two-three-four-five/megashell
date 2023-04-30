/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:25:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/30 16:46:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <shell/type.h>
#include <stdio.h>

static char	*get_unmatched_quote(t_list *lst)
{
	char	quote;
	char	*str;

	while (lst)
	{
		quote = 0;
		str = (char *)lst->content;
		while (*str)
		{
			if (!quote && isquote(*str))
				quote = *str;
			else if (quote && *str == quote)
				quote = 0;
			str++;
		}
		if (quote == '\'')
			return ("\'");
		else if (quote == '\"')
			return ("\"");
		lst = lst->next;
	}
	return (NULL);
}

t_bool	check_quote(t_list *lst)
{
	char	*token;

	token = get_unmatched_quote(lst);
	if (token)
	{
		printf("dish: `%s\': missing `%s\'\n", token, token);
		return (FALSE);
	}
	else
		return (TRUE);
}
