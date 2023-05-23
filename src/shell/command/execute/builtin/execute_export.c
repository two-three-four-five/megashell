/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:32:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 22:07:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "type.h"

static t_bool	is_valid_option(t_tree *tree)
{
	while (tree)
	{
		if (((t_token *)tree->content)->token[0] == '-')
			return (FALSE);
		tree = tree->left;
	}
	return (TRUE);
}

static int	raise_export_usage_error(t_tree *tree)
{
	while (tree)
	{
		if (((t_token *)tree->content)->token[0] == '-')
		{
			ft_putstr_fd("bash: export: ", 2);
			ft_putstr_fd(((t_token *)tree->content)->token, 2);
			ft_putendl_fd(" invalid option", 2);
			ft_putendl_fd("export: usage: export [name[=value] ...]", 2);
			return (1);
		}
		tree = tree->left;
	}
	return (1);
}

static t_bool	is_valid_arg(t_tree *tree)
{
	char	*arg;

	while (tree)
	{
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
		tree = tree->left;
	}
	return (TRUE);
}

static int	raise_export_arg_error(t_tree *tree)
{
	char	*arg;

	while (tree)
	{
		arg = ((t_token *)tree->content)->token;
		if (!ft_isalpha(*arg) && *arg != '_')
		{
			ft_putstr_fd("dish: export: `", 2);
			ft_putstr_fd(((t_token *)tree->content)->token, 2);
			ft_putendl_fd("\': not a valid identifier", 2);
			return (1);
		}
		arg++;
		while (*arg && *arg != '=')
		{
			if (!ft_isalnum(*arg) && *arg != '_')
			{
				ft_putstr_fd("dish: export: `", 2);
				ft_putstr_fd(((t_token *)tree->content)->token, 2);
				ft_putendl_fd("\': not a valid identifier", 2);
				return (1);
			}
			arg++;
		}
		tree = tree->left;
	}
	return (1);
}

int	execute_export(t_tree *tree, t_dict *env)
{
	(void)env;
	if (!is_valid_option(tree->left))
		return (raise_export_usage_error(tree->left));
	else if (!is_valid_arg(tree->left))
		return (raise_export_arg_error(tree->left));
	// normal export
	return (0);
}
