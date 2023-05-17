/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parameter_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:58:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 21:10:23 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdlib.h>

void	expand_parameter_lst(t_list *lst, t_dict *env)
{
	char	*new_token;

	lst = lst->next;
	while (lst)
	{
		if (((t_token *)lst->content)->type == WORD)
		{
			new_token = expand_parameter_token(\
				((t_token *)lst->content)->token, env);
			free(((t_token *)lst->content)->token);
			((t_token *)lst->content)->token = new_token;
		}
		lst = lst->next;
	}
}
