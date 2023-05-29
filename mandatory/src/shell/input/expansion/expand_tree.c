/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:51:08 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/29 18:02:48 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "shell/input.h"

// static void	remove_empty_word(t_list *lst);
void		expand_tree(t_tree *tree, t_dict *env);

#include <stdio.h>
void	expand_tree(t_tree *tree, t_dict *env)
{
	printf("expand %s\n", ((t_token *)tree->content)->token);
	expand_tilde_tree(tree, env);
	expand_parameter_tree(tree, env, _REALHEAD);
	// expand_filename_tree(tree);
	// split_word_tree(tree);
	// remove_empty_word(lst);
	// remove_quote_lst(lst);
	// del_token_lstlast(lst);
}

// static void	remove_empty_word(t_list *lst)
// {
// 	t_list	*prev;

// 	prev = lst;
// 	lst = lst->next;
// 	while (lst)
// 	{
// 		if (((t_token *)lst->content)->type == WORD && \
// 			*((t_token *)lst->content)->token == '\0')
// 		{
// 			prev->next = lst->next;
// 			ft_lstdelone(lst, del_token);
// 			lst = prev->next;
// 		}
// 		else
// 		{
// 			prev = lst;
// 			lst = lst->next;
// 		}
// 	}
// }
