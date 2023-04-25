/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:30:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/25 23:37:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/error.h"
#include "shell/type.h"
#include "shell/parse.h"

static char	*get_next_token(char *s)
{
	char	*token;
	char	quote;
	size_t	len;

	len = 0;
	quote = 0;
	while (s[len])
	{
		if (!len && get_operator_len(s))
		{
			len = get_operator_len(s);
			break ;
		}
		if (quote && s[len] == quote)
			quote = 0;
		else if (!quote && isquote(s[len]))
			quote = s[len];
		else if (!quote && ismeta(s[len]))
			break ;
		len++;
	}
	if (!len)
		return (NULL);
	token = (char *)ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(token, s, len + 1);
	return (token);
}

static int	check_next_token(char *s)
{
	char	quote;
	size_t	len;

	len = 0;
	quote = 0;
	while (s[len])
	{
		if (!len && get_operator_len(s))
		{
			len = get_operator_len(s);
			break ;
		}
		else if (quote && s[len] == quote)
			quote = 0;
		else if (!quote && isquote(s[len]))
			quote = s[len];
		else if (!quote && ismeta(s[len]))
			break ;
		len++;
	}
	if (quote)
		return (0);
	else
		return (1);
}

t_list	*tokenize(char *s)
{
	t_list	*lst;
	t_list	*node;
	char	*token;

	lst = NULL;
	node = NULL;
	while (*s)
	{
		while (isdelimeter(*s))
			s++;
		if (check_next_token(s))
			token = get_next_token(s);
		else
		{
			raise_error(PARSE_NOT_ENOUGH_QUOTE);
			ft_lstclear(&lst, free);
			return (NULL);
		}
		if (!token)
			break ;
		node = ft_lstnew(token);
		ft_lstadd_back(&lst, node);
		s += ft_strlen((char *)node->content);
		while (isdelimeter(*s))
			s++;
	}
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("\n")));
	return (lst);
}
