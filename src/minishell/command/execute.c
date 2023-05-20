/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:51:43 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 15:54:48 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "shell/type.h"
#include "shell/parse.h"
#include "shell/command.h"

int	execute_pipe(t_tree *node, t_dict *env)
{
	pid_t	pid[2];
	int		exit_status;
	int		status;
	int		fd[2];

	pipe(fd);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		close(fd[READ_FD]);
		dup2(fd[WRITE_FD], STDOUT_FILENO);
		exit_status = execute(node->left, env);
	}
	else
	{
		pid[1] = fork();
		if (pid[1] == 0)
		{
			close(fd[WRITE_FD]);
			dup2(fd[READ_FD], STDIN_FILENO);
			exit_status = execute(node->right, env);
		}
		else
		{
			close(fd[READ_FD]);
			close(fd[WRITE_FD]);
			waitpid(pid[0], &status, 0);
			waitpid(pid[1], &status, 0);
		}
	}
	return (WEXITSTATUS(status));
}

int	execute_subshell(t_tree *node, t_dict *env)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execute(node->left, env);
	}
	else
	{
		waitpid(pid, &status, WNOHANG);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			return (WTERMSIG(status) + 128);
	}
	return (0);
}

int	execute_and_if(t_tree *node, t_dict *env)
{
	int	exit_status;

	exit_status = execute(node->left, env);
	if (exit_status == 0)
		exit_status = execute(node->right, env);
	return (exit_status);
}

int	execute_or_if(t_tree *node, t_dict *env)
{
	int	exit_status;

	exit_status = execute(node->left, env);
	if (exit_status != 0)
		exit_status = execute(node->right, env);
	return (exit_status);
}

int	execute(t_tree *node, t_dict *env)
{
	const t_token	*token = node->content;

	if (token->type == CMD)
	{
		exec_cmd(node, env);
	}
	else if (token->type == PIPE)
	{
		execute_pipe(node, env);
	}
	else if (token->type == SUBSHELL)
	{
		execute_subshell(node, env);
	}
	else if (token->type == AND_IF)
	{
		execute_and_if(node, env);
	}
	else if (token->type == OR_IF)
	{
		execute_or_if(node, env);
	}
	return (0);
}
