/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:48:25 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 02:40:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/input.h"

static t_tree	*parse_word(t_list *lst);
static t_tree	*parse_redirect(t_list *lst);
static void		treeadd_word(t_tree **head, t_tree *node);
t_tree			*parse_command(t_list *lst);

t_tree	*parse_command(t_list *lst)
{
	t_tree	*head;
	t_list	*prev;

	head = NULL;
	while (lst)
	{
		prev = lst;
		if (((t_token *)lst->content)->type & _CMD)
		{
			treeadd_word(&head, parse_word(lst));
			lst = lst->next;
			ft_lstdelone(prev, del_token);
		}
		else if (((t_token *)lst->content)->type & _REDIRECT)
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

static void	treeadd_word(t_tree **head, t_tree *node)
{
	if (*head == NULL)
	{
		((t_token *)node->content)->type = CMD;
		ft_treeadd_leftend(head, node);
	}
	else if (((t_token *)(*head)->content)->type == CMD && \
			ft_strlen(((t_token *)(*head)->content)->token))
		ft_treeadd_leftend(head, node);
	else
	{
		((t_token *)node->content)->type = CMD;
		node->right = (*head)->right;
		del_token((*head)->content);
		free(*head);
		*head = node;
	}
}
