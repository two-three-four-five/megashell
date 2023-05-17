/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:11:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 21:07:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdlib.h>

void	remove_quote_lst(t_list *lst)
{
	char	*new_token;

	lst = lst->next;
	while (lst)
	{
		if (((t_token *)lst->content)->type == WORD)
		{
			new_token = remove_quote_token(\
				((t_token *)lst->content)->token);
			if (!new_token)
				return ;
			free(((t_token *)lst->content)->token);
			((t_token *)lst->content)->token = new_token;
		}
		lst = lst->next;
	}
}
