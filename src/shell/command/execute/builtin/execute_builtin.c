/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:09:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 18:27:13 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "type.h"

int	execute_builtin(t_tree *tree, t_dict *env)
{
	t_token	*token;

	token = tree->content;
	if (ft_strcmp(token->token, "echo") == 0)
		return (execute_echo(tree, env));
	else if (ft_strcmp(token->token, "exit") == 0)
		return (execute_exit(tree, env));
	else if (ft_strcmp(token->token, "export") == 0)
		return (execute_export(tree, env));
	else if (ft_strcmp(token->token, "unset") == 0)
		return (execute_unset(tree, env));
	else if (ft_strcmp(token->token, "env") == 0)
		return (execute_env(tree, env));
	else if (ft_strcmp(token->token, "cd") == 0)
		return (execute_cd(tree, env));
	else if (ft_strcmp(token->token, "pwd") == 0)
		return (execute_pwd(tree, env));
	exit (0);
}
