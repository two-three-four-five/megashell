/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:19:01 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 17:20:12 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell/command.h"
#include "shell/parse.h"
#include "shell/type.h"

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
	if (((t_token *)node->content)->type & HEAD)
		return (WEXITSTATUS(status));
	else
		exit(WEXITSTATUS(status));
}
