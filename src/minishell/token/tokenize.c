/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:30:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/24 21:06:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isquote(int c)
{
	if ((char)c == '\'' || (char)c == '\"')
		return (1);
	else
		return (0);
}

static char	*get_next_token(char *s)
{
	char	*token;
	size_t	len;
	char	quote;

	len = 0;
	quote = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	while (s[len])
	{
		if (quote && s[len] == quote)
			break ;
		else if (!quote && isquote((s[len])))
			quote = s[len];
		len++;
	}
	if (!len || quote)
		return (NULL);
	token = (char *)ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(token, s, len);
	return (token);
}

// 	if (!node || !node.content) needs free?

t_list	*tokenize(char *s)
{
	t_list	*lst;
	t_list	*node;
	char	*token;

	lst = NULL;
	while (true)
	{
		node = ft_lstnew(get_next_token(s));
		if (!node || !node.content)
			break ;
		ft_lstadd_back(&lst, node);
		s += ft_strlen((char *)node.content);
	}
	return (lst);
}
