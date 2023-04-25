/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:30:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/25 17:40:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdio.h>

int	get_control_operator_len(char *s)
{
	if (!ft_strncmp(";;&", s, 3))
		return (3);
	else if (!ft_strncmp("||", s, 2) || !ft_strncmp(";;", s, 2) || \
			!ft_strncmp("&&", s, 2) || !ft_strncmp(";&", s, 2) || \
			!ft_strncmp("|&", s, 2))
		return (2);
	else if (!ft_strncmp("&", s, 1) || !ft_strncmp(";", s, 1) || \
			!ft_strncmp("|", s, 1) || !ft_strncmp("(", s, 1) || \
			!ft_strncmp(")", s, 1))
		return (1);
	else
		return (0);
}

int	get_redirection_operator_len(char *s)
{
	if (!ft_strncmp("&>>", s, 3) || !ft_strncmp("<<-", s, 3) || \
		!ft_strncmp("<<<", s, 3))
		return (3);
	else if (!ft_strncmp(">|", s, 2) || !ft_strncmp(">>", s, 2) || \
			!ft_strncmp("&>", s, 2) || !ft_strncmp(">&", s, 2) || \
			!ft_strncmp("<<", s, 2) || !ft_strncmp("<&", s, 2) || \
			!ft_strncmp("<>", s, 2))
		return (2);
	else if (!ft_strncmp("<", s, 1) || !ft_strncmp(">", s, 1))
		return (1);
	else
		return (0);
}

int	get_operator_len(char *s)
{
	if (get_redirection_operator_len(s))
		return (get_redirection_operator_len(s));
	else if (get_control_operator_len(s))
		return (get_control_operator_len(s));
	else
		return (0);
}

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

static void	raise_error(int errno)
{
	if (errno == PARSE_ERR_NOT_ENOUGH_QUOTE)
		printf("parse error : not enough quote\n");
}

t_list	*tokenize(char *s)
{
	t_list	*lst;
	t_list	*node;

	lst = NULL;
	node = NULL;
	while (*s)
	{
		while (isdelimeter(*s))
			s++;
		if (check_next_token(s))
			node = ft_lstnew(get_next_token(s));
		else
			raise_error(PARSE_ERR_NOT_ENOUGH_QUOTE);
		if (!node || !node->content)
			break ;
		ft_lstadd_back(&lst, node);
		s += ft_strlen((char *)node->content);
	}
	return (lst);
}
