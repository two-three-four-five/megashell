/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_or_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:18:59 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 17:24:45 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell/command.h"
#include "shell/parse.h"
#include "shell/type.h"

int	execute_or_if(t_tree *node, t_dict *env)
{
	pid_t	pid[2];
	int		exit_status;
	int		status;

	pid[0] = fork();
	if (pid[0] == 0)
		exit_status = execute(node->left, env);
	else
	{
		waitpid(pid[0], &status, 0);
		if (WEXITSTATUS(status) == 0)
		{
			if (((t_token *)node->content)->type & HEAD)
				return (WEXITSTATUS(status));
			else
				exit(WEXITSTATUS(status));
		}
		pid[1] = fork();
		if (pid[1] == 0)
			exit_status = execute(node->right, env);
		else
		{
			waitpid(pid[1], &status, 0);
			if (((t_token *)node->content)->type & HEAD)
				return (WEXITSTATUS(status));
			else
				exit(WEXITSTATUS(status));
		}
	}
	return (0);
}
