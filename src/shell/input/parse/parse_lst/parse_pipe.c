/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:15:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 14:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/parse.h"

static t_list	*find_pipe_ptr(t_list *lst);
t_tree			*parse_pipe(t_list *lst);

t_tree	*parse_pipe(t_list *lst)
{
	t_tree	*head;
	t_list	*pipe;
	t_list	*right;

	pipe = find_pipe_ptr(lst);
	right = pipe->next;
	pipe->next = NULL;
	del_token_lstlast(lst);
	head = ft_treenew(new_token(PIPE, ft_strdup("|")));
	head->left = parse_lst(lst);
	head->right = parse_lst(right);
	return (head);
}

static t_list	*find_pipe_ptr(t_list *lst)
{
	int		subshell;

	subshell = 0;
	while (lst)
	{
		if (((t_token *)lst->content)->type == OPEN_PAREN)
			subshell++;
		else if (((t_token *)lst->content)->type == CLOSE_PAREN)
			subshell--;
		if (subshell == 0 && ((t_token *)lst->content)->type == PIPE)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
