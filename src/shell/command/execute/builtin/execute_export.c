/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:32:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/24 15:11:21 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"
#include "type.h"

static t_bool	is_valid_export_option(t_tree *tree)
{
	while (tree)
	{
		if (((t_token *)tree->content)->token[0] == '-')
			return (FALSE);
		tree = tree->left;
	}
	return (TRUE);
}

static t_bool	is_valid_export_arg(t_tree *tree)
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

int	execute_export(t_tree *tree, t_dict *env)
{
	(void)env;
	if (!is_valid_export_option(tree->left))
		return (raise_export_usage_error(tree->left));
	else if (!is_valid_export_arg(tree->left))
		return (raise_export_arg_error(tree->left));
	else if (!tree->left)
		return (execute_export_nop(tree, env));
	else
		return (execute_export_op(tree, env));
	return (0);
}
