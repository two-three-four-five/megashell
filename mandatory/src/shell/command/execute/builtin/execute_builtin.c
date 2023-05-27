/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:09:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/27 23:55:58 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "shell.h"
#include "type.h"

static int	(*get_builtin_function(char *cmd))(t_tree *, t_dict *);

static void	restore_fd(int stdin_fd, int stdout_fd)
{
	close(0);
	close(1);
	dup2(stdin_fd, 0);
	dup2(stdout_fd, 1);
	close(stdin_fd);
	close(stdout_fd);
}

int	execute_builtin(t_tree *tree, t_dict *env)
{
	t_token	*token;
	int		exit_status;
	int		stdin_fd;
	int		stdout_fd;

	token = tree->content;
	if (token->type & _HEAD)
	{
		stdin_fd = dup(STDIN_FILENO);
		stdout_fd = dup(STDOUT_FILENO);
	}
	if (redirect_fd(tree) < 0)
	{
		restore_fd(stdin_fd, stdout_fd);
		return (1);
	}
	exit_status = get_builtin_function(token->token)(tree, env);
	if (token->type & _HEAD)
	{
		restore_fd(stdin_fd, stdout_fd);
		return (exit_status);
	}
	else
		exit(exit_status);
}

static int	(*get_builtin_function(char *cmd))(t_tree *tree, t_dict *env)
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
