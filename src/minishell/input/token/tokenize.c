/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:30:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 17:33:46 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"

static void	*tokenize_failed(t_list **lst, t_list *node);
static char	*skip_delimeter(const char *s);

t_list	*tokenize(char *s)
{
	t_list	*lst;
	t_list	*node;

	lst = ft_lstnew(NULL);
	if (!lst)
		return (NULL);
	node = NULL;
	while (*s)
	{
		s = skip_delimeter(s);
		if (*s == '#')
			break ;
		node = ft_lstnew(get_next_token(s));
		if (!node || !node->content)
			return (tokenize_failed(&lst, node));
		ft_lstadd_back(&lst, node);
		s += ft_strlen(((t_token *)node->content)->token);
		s = skip_delimeter(s);
	}
	node = ft_lstnew(new_token(NEWLINE, ft_strdup("\n")));
	if (!node || !node->content)
		return (tokenize_failed(&lst, node));
	ft_lstadd_back(&lst, node);
	return (lst);
}

static void	*tokenize_failed(t_list **lst, t_list *node)
{
	if (*lst)
		ft_lstclear(lst, del_token);
	if (node)
	{
		if (node->content)
			free(node->content);
		free(node);
	}
	return (NULL);
}

static char	*skip_delimeter(const char *s)
{
	while (isdelimeter(*s))
		s++;
	return ((char *)s);
}
