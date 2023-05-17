/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell_with_redirect.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:42:15 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 17:07:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"


#include <stdio.h>

static t_list	*find_close_paran_ptr(t_list *lst);
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
	head->right = parse_lst(lst);
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
