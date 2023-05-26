/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:15:28 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type_bonus.h"
#include "shell/input_bonus.h"

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
	t_list	*pipe;

	subshell = 0;
	pipe = NULL;
	while (lst)
	{
		if (((t_token *)lst->content)->type == OPEN_PAREN)
			subshell++;
		else if (((t_token *)lst->content)->type == CLOSE_PAREN)
			subshell--;
		if (subshell == 0 && ((t_token *)lst->content)->type == PIPE)
			pipe = lst;
		lst = lst->next;
	}
	return (pipe);
}
