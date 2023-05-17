/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:48:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 17:08:54 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"

static t_tree	*parse_word(t_list *lst);
static t_tree	*parse_redirect(t_list *lst);
t_tree			*parse_command(t_list *lst);

t_tree	*parse_command(t_list *lst)
{
	t_tree	*head;
	t_list	*prev;

	while (lst)
	{
		prev = lst;
		if (((t_token *)lst->content)->type == WORD)
		{
			ft_treeadd_leftend(&head, parse_word(lst));
			lst = lst->next;
			ft_lstdelone(prev, del_token);
		}
		else if (((t_token *)lst->content)->type & REDIRECT)
		{
			if (!head)
				head = ft_treenew(new_token(WORD, ft_strdup("")));
			ft_treeadd_rightend(&head, parse_redirect(lst));
			lst = lst->next->next;
			prev->next->next = NULL;
			ft_lstclear(&prev, del_token);
		}
	}
	return (head);
}

static t_tree	*parse_word(t_list *lst)
{
	t_tree	*head;

	head = ft_treenew(\
				new_token(WORD, ft_strdup(((t_token *)lst->content)->token)));
	return (head);
}

static t_tree	*parse_redirect(t_list *lst)
{
	t_tree	*head;

	head = ft_treenew(\
				new_token(((t_token *)lst->content)->type, \
					ft_strdup(((t_token *)lst->content)->token)));
	head->left = ft_treenew(\
					new_token(((t_token *)lst->next->content)->type, \
						ft_strdup(((t_token *)lst->next->content)->token)));
	return (head);
}
