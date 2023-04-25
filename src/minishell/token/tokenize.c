/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:30:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/26 00:02:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"

static void	*clear_lst(t_list **lst, void (*del)(void *));
static char	*skip_delimeter(const char *s);

t_list	*tokenize(char *s)
{
	t_list	*lst;
	t_list	*node;

	lst = NULL;
	node = NULL;
	while (*s)
	{
		s = skip_delimeter(s);
		node = ft_lstnew(get_next_token(s));
		if (!node || !node->content)
			return (clear_lst(&lst, free));
		ft_lstadd_back(&lst, node);
		s += ft_strlen((char *)node->content);
		s = skip_delimeter(s);
	}
	node = ft_lstnew(ft_strdup("\n"));
	if (!node || !node->content)
		return (clear_lst(&lst, free));
	ft_lstadd_back(&lst, node);
	return (lst);
}

static void	*clear_lst(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}

static char	*skip_delimeter(const char *s)
{
	while (isdelimeter(*s))
		s++;
	return (s);
}
