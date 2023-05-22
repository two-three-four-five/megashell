/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:57:13 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 14:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell/command.h"
#include "shell/envp.h"
#include "shell/parse.h"
#include "type.h"

static t_bool	is_executable(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (TRUE);
	else
		return (FALSE);
}

static void	raise_exec_error(t_tree *tree)
{
	(void) tree;
	ft_putstr_fd("ERROR\n", 2);
	if ((((t_token *)tree->content)->type & HEAD) == 0)
		exit(1);
}

static int	execute_cmd_head(t_tree *tree, t_dict *env)
{
	pid_t	pid;
	int		status;
	char	**argv;
	char	**envp;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (redirect_fd(tree) < 0)
			exit(1);
		argv = get_argv(tree);
		envp = get_envp(env);
		execve(((t_token *)tree->content)->token, argv, envp);
	}
	else
	{
		waitpid(pid, &status, 0);
		return (get_exit_status(status));
	}
	return (-1);
}

int	execute_cmd(t_tree *tree, t_dict *env)
{
	const t_token	*token = tree->content;
	char			**argv;
	char			**envp;

	if (token->type & HEAD && is_builtin_cmd(token->token))
		return (execute_builtin(tree, env));
	else if (!(token->type & HEAD) && is_builtin_cmd(token->token))
		return (execute_builtin(tree, env));
	else if (token->type & HEAD && is_executable(token->token))
		return (execute_cmd_head(tree, env));
	else if (!(token->type & HEAD) && is_executable(token->token))
	{
		if (redirect_fd(tree) < 0)
			return (1);
		argv = get_argv(tree);
		envp = get_envp(env);
		return (execve(token->token, argv, envp));
	}
	else
		raise_exec_error(tree);
	return (1);
}