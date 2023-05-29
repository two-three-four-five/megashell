/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:05:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/29 18:00:30 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "shell/input.h"
#include "type.h"

static char	*expand_tilde_token(char *token, t_dict *env);
void		expand_tilde_lst(t_list *lst, t_dict *env);

void	expand_tilde_tree(t_tree *tree, t_dict *env)
{
	t_token	*token;
	char	*new_token;

	token = tree->content;
	if (token->type == WORD)
	{
		if (!ft_strncmp("~/", token->token, 2) || \
			!ft_strcmp("~", token->token))
		{
			new_token = expand_tilde_token(\
							token->token, \
							env);
			free(token->token);
			token->token = new_token;
		}
	}
	if (tree->left)
		expand_tilde_tree(tree->left, env);
	if (tree->right)
		expand_tilde_tree(tree->right, env);
}

static char	*expand_tilde_token(char *token, t_dict *env)
{
	char	*new_token;

	(void)env;
	new_token = ft_strjoin(getenv("HOME"), token + 1);
	return (new_token);
}
