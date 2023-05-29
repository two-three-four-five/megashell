/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:05:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/29 18:00:33 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "shell/input.h"
#include "type.h"

static char	*expand_tilde_token(char *token, t_dict *env);
void		expand_tilde_lst(t_list *lst, t_dict *env);

void	expand_tilde_lst(t_list *lst, t_dict *env)
{
	char	*new_token;

	lst = lst->next;
	while (lst)
	{
		if (((t_token *)lst->content)->type == WORD)
		{
			if (!ft_strncmp("~/", ((t_token *)lst->content)->token, 2) || \
				!ft_strcmp("~", ((t_token *)lst->content)->token))
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

static char	*expand_tilde_token(char *token, t_dict *env)
{
	char	*new_token;

	(void)env;
	new_token = ft_strjoin(getenv("HOME"), token + 1);
	return (new_token);
}
