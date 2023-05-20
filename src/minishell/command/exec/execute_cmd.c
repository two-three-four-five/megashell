/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:57:13 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 17:42:23 by jinhchoi         ###   ########.fr       */
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

static void	free_strp(char **strp)
{
	int	idx;

	idx = 0;
	while (strp[idx])
		free(strp[idx]);
	free(strp);
}

static void	raise_exec_error(t_tree *tree)
{
	(void) tree;
	ft_putstr_fd("ERROR\n", 2);
	if ((((t_token *)tree->content)->type & HEAD) == 0)
		exit(1);
}

int	execute_cmd(t_tree *tree, t_dict *env)
{
	const t_token	*token = tree->content;
	char			**argv;
	char			**envp;

	argv = get_argv(tree);
	envp = get_envp(env);
	if (is_builtin_cmd(token->token))
	{
		execute_builtin(argv, envp);
		free_strp(argv);
		free_strp(envp);
	}
	else if (is_executable(token->token))
	{
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
				// free_strp(argv);
				// free_strp(envp);
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
