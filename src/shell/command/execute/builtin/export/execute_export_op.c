/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:57:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/23 16:06:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "type.h"

static void	alter_env_without_init(char *token, t_dict *env);
static void	alter_env_with_init(char *token, t_dict *env);
int			execute_export_op(t_tree *tree, t_dict *env);

int	execute_export_op(t_tree *tree, t_dict *env)
{
	char	*token;

	tree = tree->left;
	while (tree)
	{
		token = ((t_token *)tree->content)->token;
		if (ft_strchr(token, '=') == NULL)
			alter_env_without_init(token, env);
		else
			alter_env_with_init(token, env);
		tree = tree->left;
	}
	return (0);
}

static void	alter_env_without_init(char *token, t_dict *env)
{
	char	*key;
	t_dict	*node;

	key = ft_strdup(token);
	if (get_dict_value(env->next, key) == NULL)
	{
		node = ft_lstnew(new_str_pair(key, ft_strdup("")));
		ft_lstadd_back(&env, node);
	}
	else
		free(key);
}

static void	alter_env_with_init(char *token, t_dict *env)
{
	char	*key;
	char	*value;
	t_dict	*node;

	key = ft_substr(token, 0, ft_strchr(token, '=') - token);
	value = ft_strdup(ft_strchr(token, '=') + 1);
	if (get_dict_value(env->next, key) == NULL)
	{
		node = ft_lstnew(new_str_pair(key, value));
		ft_lstadd_back(&env, node);
	}
	else
	{
		reassign_dict_value(env->next, key, value);
		free(key);
	}
}
