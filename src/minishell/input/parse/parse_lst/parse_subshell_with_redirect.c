/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell_with_redirect.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:42:15 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/18 21:07:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"


#include <stdio.h>

static t_list	*find_close_paran_ptr(t_list *lst);
static t_tree	*parse_remaining_redirect(t_list *lst);
static t_tree	*parse_redirect(t_list *lst);
t_tree			*parse_subshell_with_redirect(t_list *lst);

t_tree	*parse_subshell_with_redirect(t_list *lst)
{
	t_tree	*head;
	t_list	*close_paren;
	t_list	*right;

	close_paren = find_close_paran_ptr(lst);
	right = close_paren->next;
	close_paren->next = NULL;
	head = parse_lst(lst);
	head->right = parse_remaining_redirect(right);
	return (head);
}

static t_list	*find_close_paran_ptr(t_list *lst)
{
	int		subshell;

	subshell = 0;
	while (lst)
	{
		if (((t_token *)lst->content)->type == OPEN_PAREN)
			subshell++;
		else if (((t_token *)lst->content)->type == CLOSE_PAREN)
			subshell--;
		if (subshell == 0 && ((t_token *)lst->content)->type == CLOSE_PAREN)
			return (lst);
		else if (subshell == 0)
			printf("********** ERROR !!!! ***********");
		lst = lst->next;
	}
	return (NULL);
}

static t_tree	*parse_remaining_redirect(t_list *lst)
{
	t_tree	*head;
	t_list	*prev;

	head = NULL;
	while (lst)
	{
		prev = lst;
		if (((t_token *)lst->content)->type & REDIRECT)
		{
			ft_treeadd_rightend(&head, parse_redirect(lst));
			lst = lst->next->next;
			prev->next->next = NULL;
			ft_lstclear(&prev, del_token);
		}
	}
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
