/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:29:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 20:59:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	unset_env(t_dict *env, char *str);

int	execute_unset(t_tree *tree, t_dict *env)
{
	tree = tree->left;
	while (tree)
	{
		unset_env(env, ((t_token *)tree->content)->token);
		tree = tree->left;
	}
	return (0);
}

static void	unset_env(t_dict *env, char *str)
{
	t_dict	*curr;
	t_dict	*prev;

	prev = env;
	curr = env->next;
	while (curr)
	{
		if (!ft_strcmp(((t_str_pair *)curr->content)->s1, str))
		{
			prev->next = curr->next;
			ft_lstdelone(curr, del_str_pair);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
