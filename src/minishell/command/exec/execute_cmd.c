/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:57:13 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 16:45:13 by jinhchoi         ###   ########.fr       */
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

static char	**get_argv(t_tree *tree)
{
	char	**argv;
	int		idx;

	argv = ft_calloc(ft_treeleftsize(tree) + 1, sizeof(char *));
	idx = 0;
	while (tree)
	{
		argv[idx++] = ft_strdup(((t_token *)tree->content)->token);
		tree = tree->left;
	}
	return (argv);
}

static void	raise_exec_error(t_tree *tree)
{
	(void) tree;
	ft_putstr_fd("ERROR\n", 2);
	exit(1);
}

int	execute_cmd(t_tree *tree, t_dict *env)
{
	const t_token	*token = tree->content;
	char			**argv;
	char			**envp;

	envp = get_envp(env);
	if (is_builtin_cmd(token->token))
	{
		execute_builtin(tree, env);
	}
	else if (is_executable(token->token))
	{
		argv = get_argv(tree);
		if (token->type & HEAD)
		{
			pid_t	pid;
			int		status;
			pid = fork();
			if (pid == 0)
			{
				execve(token->token, argv, envp);
			}
			else
			{
				wait(&status);
				return (WEXITSTATUS(status));
			}
		}
		execve(token->token, argv, envp);
	}
	else
	{
		raise_exec_error(tree);
	}
	return (0);
}
