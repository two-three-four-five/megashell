/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:05:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/24 16:09:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "type.h"
#include "shell/input.h"

char	*expand_tilde_token(char *token, t_dict *env);
void	expand_tilde_lst(t_list *lst, t_dict *env);

void	expand_tilde_lst(t_list *lst, t_dict *env)
{
	char	*new_token;

	lst = lst->next;
	while (lst)
	{
		if (((t_token *)lst->content)->type == WORD)
		{
			if (!ft_strncmp("~/", ((t_token *)lst->content)->token, 2) || \
				!ft_strncmp("~", ((t_token *)lst->content)->token, 1))
			{
				new_token = expand_tilde_token(\
								((t_token *)lst->content)->token, \
								env);
				free(((t_token *)lst->content)->token);
				((t_token *)lst->content)->token = new_token;
			}
		}
		lst = lst->next;
	}
}

char	*expand_tilde_token(char *token, t_dict *env)
{
	char	*new_token;

	new_token = ft_strjoin(getenv("HOME"), token + 1);
	return (new_token);
}
