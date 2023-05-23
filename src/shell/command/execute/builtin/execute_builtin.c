/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:09:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 20:30:09 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"
#include "type.h"

static int	(*get_matching_function(char *cmd))(t_tree *, t_dict *);

t_bool	is_executed_in_parent(char *cmd)
{
	if (ft_strcmp(cmd, "exit") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd, "export") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (TRUE);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (TRUE);
	else
		return (FALSE);
}

static int	execute_builtin_in_head(t_tree *tree, t_dict *env)
{
	t_token	*token;
	pid_t	pid;
	int		status;

	token = tree->content;
	pid = fork();
	if (pid == 0 && !is_executed_in_parent(token->token))
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (redirect_fd(tree) < 0)
			exit(1);
		exit(get_matching_function(token->token)(tree, env));
	}
	else if (pid == 0)
		exit(0);
	else if (is_executed_in_parent(token->token))
		return (get_matching_function(token->token)(tree, env));
	else
	{
		waitpid(pid, &status, 0);
		return (get_exit_status(status));
	}
	return (-1);
}

int	execute_builtin(t_tree *tree, t_dict *env)
{
	t_token	*token;

	token = tree->content;
	if (token->type & HEAD && !is_executed_in_parent(token->token))
		return (execute_builtin_in_head(tree, env));
	else if (token->type & HEAD && is_executed_in_parent(token->token))
		return (execute_builtin_in_head(tree, env));
	if (redirect_fd(tree) < 0)
		return (1);
	return (get_matching_function(token->token)(tree, env));
}

static int	(*get_matching_function(char *cmd))(t_tree *tree, t_dict *env)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (execute_echo);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (execute_exit);
	else if (ft_strcmp(cmd, "export") == 0)
		return (execute_export);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (execute_unset);
	else if (ft_strcmp(cmd, "env") == 0)
		return (execute_env);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (execute_cd);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (execute_pwd);
	else
		return (NULL);
}
