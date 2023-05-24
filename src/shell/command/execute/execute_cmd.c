/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:57:13 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/24 13:26:41 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "shell.h"
#include "type.h"

static int	raise_exec_error(t_tree *tree)
{
	t_token	*token;

	token = tree->content;
	if (!is_file_exist(token->token) && !ft_strchr(token->token, '/'))
		return (raise_cmd_error(COMMAND_NOT_FOUND, token->token));
	else if (!is_file_exist(token->token) && ft_strchr(token->token, '/'))
		return (raise_cmd_error(NO_SUCH_FILE_OR_DIRECTORY, token->token));
	else if (is_directory(token->token))
		return (raise_cmd_error(IS_A_DIRECTORY, token->token));
	else if (!is_executable(token->token) && ft_strchr(token->token, '/'))
		return (raise_cmd_error(PERMISSION_DENIED, token->token));
	else if (!is_executable(token->token))
		return (raise_cmd_error(COMMAND_NOT_FOUND, token->token));
	else
		return (-1);
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
		envp = get_envp(env->next);
		execve(((t_token *)tree->content)->token, argv, envp);
	}
	else
	{
		waitpid(pid, &status, 0);
		return (get_exit_status(status));
	}
	return (-1);
}

static int	execute_empty_cmd(t_tree *tree, t_dict *env)
{
	pid_t	pid;
	int		status;

	(void)env;
	pid = fork();
	if (pid == 0)
	{
		if (redirect_fd(tree) < 0)
			exit(1);
		else
			exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		return (get_exit_status(status));
	}
	return (0);
}

int	execute_cmd(t_tree *tree, t_dict *env)
{
	const t_token	*token = tree->content;
	char			**argv;
	char			**envp;
	char			*cmd;

	cmd = token->token;
	if (ft_strlen(token->token) == 0)
		return (execute_empty_cmd(tree, env));
	else if (token->type & _HEAD && is_builtin_cmd(cmd))
		return (execute_builtin(tree, env));
	else if (!(token->type & _HEAD) && is_builtin_cmd(cmd))
		exit(execute_builtin(tree, env));
	else if (token->type & _HEAD && !is_directory(cmd) && is_executable(cmd))
		return (execute_cmd_head(tree, env));
	else if (!(token->type & _HEAD) && !is_directory(cmd) && is_executable(cmd))
	{
		if (redirect_fd(tree) < 0)
			return (1);
		argv = get_argv(tree);
		envp = get_envp(env->next);
		return (execve(cmd, argv, envp));
	}
	else if (!(token->type & _HEAD))
		exit(raise_exec_error(tree));
	else
		return (raise_exec_error(tree));
	return (1);
}
