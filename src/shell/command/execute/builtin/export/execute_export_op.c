/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:57:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 17:57:14 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "type.h"

static t_bool	is_valid_export_option(t_tree *tree);
static t_bool	is_valid_export_arg(t_tree *tree);
static void		alter_env_without_init(char *token, t_dict *env);
static void		alter_env_with_init(char *token, t_dict *env);
int				execute_export_op(t_tree *tree, t_dict *env);

int	execute_export_op(t_tree *tree, t_dict *env)
{
	char	*token;
	int		ret;

	if (!is_valid_export_option(tree->left))
		return (raise_export_usage_error(tree->left));
	tree = tree->left;
	ret = 0;
	while (tree)
	{
		if (!is_valid_export_arg(tree))
			ret = raise_export_arg_error(tree);
		else
		{
			token = ((t_token *)tree->content)->token;
			if (ft_strchr(token, '=') == NULL)
				alter_env_without_init(token, env);
			else
				alter_env_with_init(token, env);
		}
		tree = tree->left;
	}
	return (ret);
}

static t_bool	is_valid_export_option(t_tree *tree)
{
	while (tree)
	{
		if (((t_token *)tree->content)->token[0] == '-')
			return (FALSE);
		else
			break ;
		tree = tree->left;
	}
	return (TRUE);
}

static t_bool	is_valid_export_arg(t_tree *tree)
{
	char	*arg;

	arg = ((t_token *)tree->content)->token;
	if (!ft_isalpha(*arg) && *arg != '_')
		return (FALSE);
	arg++;
	while (*arg && *arg != '=')
	{
		if (!ft_isalnum(*arg) && *arg != '_')
			return (FALSE);
		arg++;
	}
	return (TRUE);
}


static void	alter_env_without_init(char *token, t_dict *env)
{
	char	*key;
	t_dict	*node;

	key = ft_strdup(token);
	if (!has_dict_key(env->next, key))
	{
		node = ft_lstnew(new_str_pair(key, NULL));
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
	if (!has_dict_key(env->next, key))
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
