/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:51:08 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 16:08:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"
#include "shell/parse.h"

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



void	expand(t_list *lst, t_dict *env)
{
	expand_tilde(lst, env);
	expand_parameter(lst, env);
	expand_filename(lst);
	split_word(lst);
	remove_empty_word(lst);
	remove_quote(lst);
	del_token_lstlast(lst);
}
