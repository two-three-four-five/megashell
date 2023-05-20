/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:18:55 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 17:24:53 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "shell/command.h"
#include "shell/type.h"

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
