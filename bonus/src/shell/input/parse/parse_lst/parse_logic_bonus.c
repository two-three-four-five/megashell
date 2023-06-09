/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_logic_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:31:12 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type_bonus.h"
#include "shell/input_bonus.h"

static t_list	*find_logic_ptr(t_list *lst);
t_tree			*parse_logic(t_list *lst);

t_tree	*parse_logic(t_list *lst)
{
	t_tree	*head;
	t_list	*logic;
	t_list	*right;
	char	*logic_operator;

	logic = find_logic_ptr(lst);
	right = logic->next;
	logic->next = NULL;
	logic_operator = ft_strdup(((t_token *)logic->content)->token);
	head = ft_treenew(new_token(((t_token *)logic->content)->type, \
						logic_operator));
	del_token_lstlast(lst);
	head->left = parse_lst(lst);
	head->right = parse_lst(right);
	return (head);
}

static t_list	*find_logic_ptr(t_list *lst)
{
	int		subshell;

	subshell = 0;
	while (lst)
	{
		if (((t_token *)lst->content)->type == OPEN_PAREN)
			subshell++;
		else if (((t_token *)lst->content)->type == CLOSE_PAREN)
			subshell--;
		if (subshell == 0 && ((t_token *)lst->content)->type & _LOGIC)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
