/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_or_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:18:59 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 15:51:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell/command.h"
#include "shell/input.h"
#include "type.h"

int	execute_or_if(t_tree *tree, t_dict *env)
{
	pid_t	pid[2];
	int		status;

	pid[0] = fork();
	if (pid[0] == 0)
		execute_in_child(tree->left, env);
	waitpid(pid[0], &status, 0);
	if (get_exit_status(status) == 0 || get_exit_status(status) == 130)
	{
		if (((t_token *)tree->content)->type & HEAD)
			return (get_exit_status(status));
		else
			exit(get_exit_status(status));
	}
	pid[1] = fork();
	if (pid[1] == 0)
		execute_in_child(tree->right, env);
	waitpid(pid[1], &status, 0);
	if (((t_token *)tree->content)->type & HEAD)
		return (get_exit_status(status));
	else
		exit(get_exit_status(status));
	return (0);
}
