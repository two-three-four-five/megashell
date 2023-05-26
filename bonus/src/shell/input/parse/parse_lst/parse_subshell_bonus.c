/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:11:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type_bonus.h"
#include "shell/input_bonus.h"

t_tree	*parse_subshell(t_list *lst)
{
	t_tree	*head;

	del_token_lstlast(lst);
	head = ft_treenew(new_token(_SUBSHELL, ft_strdup("()")));
	head->left = parse_lst(lst->next);
	head->right = NULL;
	ft_lstdelone(lst, del_token);
	return (head);
}
