/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirect_syntax_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:56:24 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_bonus.h"
#include "type_bonus.h"

t_bool	check_redirect_syntax(t_list *lst, t_dict *env)
{
	int		prev;
	char	*temp;

	prev = UNDEFINED;
	while (lst)
	{
		if ((prev & _REDIRECT) && (prev != DLESS))
		{
			temp = expand_parameter_token(\
				((t_token *)lst->content)->token, env);
			if (ft_strlen(temp) == 0)
			{
				free(temp);
				raise_redirect_error(((t_token *)lst->content)->token);
				return (FALSE);
			}
			free(temp);
		}
		prev = ((t_token *)lst->content)->type;
		lst = lst->next;
	}
	return (TRUE);
}
