/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_shell_bonus_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:42:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "shell_bonus.h"
#include "type_bonus.h"

static void	update_tree_head(t_tree *tree, t_bool ishead);

void	execute_shell(char **envp)
{
	t_dict		*env;
	char		*input;
	t_tree		*ptree;

	env = get_envp_dict(envp);
	while (TRUE)
	{
		input = readline("dish""-""1.2.5""$ ");
		if (!input)
			raise_exit();
		ptree = parse_input(input, env);
		if (ptree)
		{
			substitute_command_tree(ptree, env);
			update_tree_head(ptree, TRUE);
			((t_token *)ptree->content)->type |= _REALHEAD;
			signal(SIGINT, handle_sigint_in_execution);
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
		update_tree_head(tree->left, TRUE);
	else
		update_tree_head(tree->left, FALSE);
	update_tree_head(tree->right, FALSE);
}
