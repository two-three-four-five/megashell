/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:30:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/25 15:59:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

enum e_bool
{
	false,
	true
};

enum e_error
{
	PARSE_ERR_NOT_ENOUGH_QUOTE = 1
};

static int	isquote(int c)
{
	if ((char)c == '\'' || (char)c == '\"')
		return (1);
	else
		return (0);
}

static int	isdelimeter(int c)
{
	if ((char)c == ' ' || (char)c == '\t' || \
		(char)c == '\n')
		return (1);
	else
		return (0);
}

static int	isoperator(int c)
{
	if ((char)c == '|' || (char)c == '&' || \
		(char)c == ';' || (char)c == '(' || \
		(char)c == ')' || (char)c == '<' || \
		(char)c == '>')
		return (1);
	else
		return (0);
}

static int	ismeta(int c)
{
	if (isdelimeter(c) || isoperator(c))
		return (1);
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
		if (!len && isoperator(s[len]))
		{
			len++;
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
		if (!len && isoperator(s[len]))
		{
			len++;
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

void	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("%d : %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

int	main(void)
{
	char	*input;

	while (true)
	{
		input = readline("dish-0.1$");
		printf("line : %s\n", input);
		ft_lstprint(tokenize(input));
		add_history(input);
		free(input);
	}
	return (0);
}
