/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:19:01 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/21 03:55:14 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell/command.h"
#include "shell/parse.h"
#include "shell/type.h"

static int	execute_pipe_left(t_tree *node, t_dict *env, int *fd)
{
	close(fd[READ_FD]);
	dup2(fd[WRITE_FD], STDOUT_FILENO);
	return (execute(node->left, env));
}

static int	execute_pipe_right(t_tree *node, t_dict *env, int *fd)
{
	close(fd[WRITE_FD]);
	dup2(fd[READ_FD], STDIN_FILENO);
	return (execute(node->right, env));
}

int	execute_pipe(t_tree *tree, t_dict *env)
{
	pid_t	pid[2];
	int		status;
	int		fd[2];

	pipe(fd);
	pid[0] = fork();
	if (pid[0] == 0)
		execute_pipe_left(tree, env, fd);
	pid[1] = fork();
	if (pid[1] == 0)
		execute_pipe_right(tree, env, fd);
	close(fd[READ_FD]);
	close(fd[WRITE_FD]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	if (((t_token *)tree->content)->type & HEAD)
		return (get_exit_status(status));
	else
		exit(get_exit_status(status));
}
