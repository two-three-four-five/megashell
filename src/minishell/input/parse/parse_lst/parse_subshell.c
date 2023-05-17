/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:11:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 16:15:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"

t_tree	*parse_subshell(t_list *lst)
{
	t_tree	*head;

	del_token_lstlast(lst);
	head = ft_treenew(new_token(SUBSHELL, ft_strdup("()")));
	head->left = parse_lst(lst->next);
	head->right = NULL;
	ft_lstdelone(lst, del_token);
	return (head);
}
