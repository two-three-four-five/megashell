/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subshell_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:18:55 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "shell/command_bonus.h"
#include "type_bonus.h"

int	execute_subshell(t_tree *tree, t_dict *env)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (redirect_fd(tree) < 0)
			exit(1);
		exit(execute(tree->left, env));
	}
	else
	{
		waitpid(pid, &status, 0);
		return (get_exit_status(status));
	}
	return (0);
}
