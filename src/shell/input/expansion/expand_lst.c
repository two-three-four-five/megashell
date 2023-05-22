/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:51:08 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 15:51:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "shell/input.h"

static void	remove_empty_word(t_list *lst);
void		expand_lst(t_list *lst, t_dict *env);

void	expand_lst(t_list *lst, t_dict *env)
{
	expand_tilde_lst(lst, env);
	expand_parameter_lst(lst, env);
	expand_filename_lst(lst);
	split_word_lst(lst);
	remove_empty_word(lst);
	remove_quote_lst(lst);
	del_token_lstlast(lst);
}

static void	remove_empty_word(t_list *lst)
{
	t_list	*prev;

	prev = lst;
	lst = lst->next;
	while (lst)
	{
		if (((t_token *)lst->content)->type == WORD && \
			*((t_token *)lst->content)->token == '\0')
		{
			prev->next = lst->next;
			ft_lstdelone(lst, del_token);
			lst = prev->next;
		}
		else
		{
			prev = lst;
			lst = lst->next;
		}
	}
}
