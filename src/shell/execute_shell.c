/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:42:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 03:21:20 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "shell.h"
#include "type.h"

static void	update_tree_head(t_tree *tree, t_bool ishead);

void	execute_shell(char **envp)
{
	t_dict		*env;
	char		*input;
	t_tree		*ptree;

	env = get_envp_dict(envp);
	while (TRUE)
	{
		input = readline(RED"dish"END"-"YEL"1.2.5"END"$ ");
		if (!input)
			raise_exit();
		ptree = parse_input(input, env);
		if (ptree)
		{
			substitute_command_tree(ptree, env);
			update_tree_head(ptree, TRUE);
			g_exit_status = execute(ptree, env);
			set_signal_handler();
			del_heredoc_tmp_files(ptree);
			ft_treeclear(&ptree, del_token);
		}
		free(input);
	}
	ft_lstclear(&env, del_str_pair);
}

static void	update_tree_head(t_tree *tree, t_bool ishead)
{
	if (tree == NULL)
		return ;
	if (ishead)
		((t_token *)tree->content)->type |= _HEAD;
	if (((t_token *)tree->content)->type & _SUBSHELL)
		make_head(tree->left, TRUE);
	else
		make_head(tree->left, FALSE);
	make_head(tree->right, FALSE);
}
