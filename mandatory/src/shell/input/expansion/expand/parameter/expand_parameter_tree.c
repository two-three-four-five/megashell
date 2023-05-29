/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parameter_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:58:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/29 17:46:32 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/input.h"
#include <stdlib.h>

void	expand_parameter_tree(t_tree *tree, t_dict *env, int parent)
{
	t_token	*token;
	char	*new_token;

	token = tree->content;
	if (token->type == WORD)
	{
		new_token = expand_parameter_token(\
			token->token, env);
		if (parent & _REDIRECT && parent != DLESS && ft_strlen(new_token) == 0)
		{
			free(new_token);
			token->type = AMBIGUOUS;
		}
		else
		{
			free(token->token);
			token->token = new_token;
		}
	}
	if (tree->left)
		expand_parameter_tree(tree->left, env, token->type);
	if (tree->right)
		expand_parameter_tree(tree->right, env, token->type);
}
