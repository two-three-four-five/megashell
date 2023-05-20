/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:57:13 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/21 01:46:40 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell/command.h"
#include "shell/envp.h"
#include "shell/parse.h"
#include "shell/type.h"

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

// #include <fcntl.h>
// #include "shell/error.h"

// int	raise_file_error(int errno, char *filename, int type)
// {

// }

// int	check_file(char *filename, int type)
// {
// 	if (access(filename, F_OK) != 0)
// 		return (NO_SUCH_FILE_OR_DIRECTORY);
// }

// int	open_file(char *filename, int type)
// {
// 	int	fd;
// 	int	check;

// 	check = raise_file_error
// 	if (type == LESS)
// 		fd = open(filename, O_RDONLY);
// 	else if (type == DLESS)
// 		fd = open(filename, O_RDONLY);
// 	else if (type == GREAT)
// 		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	else if (type == DGREAT)
// 		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 	if (fd < 0)
// }

// int	redirect_fd(t_tree *tree)
// {
// 	int	type;

// 	tree = tree->right;
// 	while (tree)
// 	{
// 		type = ((t_token *)tree->content)->type;
// 		if (type & REDIRECT_OUT)
// 		{

// 		}
// 		else
// 		{
			
// 		}
// 		tree = tree->right;
// 	}
// 	return (0);
// }

int	execute_cmd(t_tree *tree, t_dict *env)
{
	const t_token	*token = tree->content;
	char			**argv;
	char			**envp;

	if (is_builtin_cmd(token->token))
		execute_builtin(tree, env);
	else if (is_executable(token->token))
	{
		if (token->type & HEAD)
			execute_cmd_head(tree, env);
		else
		{
			argv = get_argv(tree);
			envp = get_envp(env);
			execve(token->token, argv, envp);
		}
	}
	else
		raise_exec_error(tree);
	return (0);
}
