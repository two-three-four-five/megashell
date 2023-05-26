/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parameter_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:58:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 19:02:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/input.h"
#include <stdlib.h>

void	expand_parameter_lst(t_list *lst, t_dict *env)
{
	int		prev;
	char	*new_token;

	prev = UNDEFINED;
	lst = lst->next;
	while (lst)
	{
		if (((t_token *)lst->content)->type == WORD)
		{
			new_token = expand_parameter_token(\
				((t_token *)lst->content)->token, env);
			if (prev & _REDIRECT && prev != DLESS && ft_strlen(new_token) == 0)
			{
				free(new_token);
				((t_token *)lst->content)->type = AMBIGUOUS;
			}
			else
			{
				free(((t_token *)lst->content)->token);
				((t_token *)lst->content)->token = new_token;
			}
		}
		prev = ((t_token *)lst->content)->type;
		lst = lst->next;
	}
}
