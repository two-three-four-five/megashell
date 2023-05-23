/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:42:54 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/23 21:32:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "shell.h"
#include "type.h"

void	execute_shell(char **envp)
{
	t_dict		*env;
	char		*input;
	t_tree		*ptree;

	env = get_envp_dict(envp);
	while (TRUE)
	{
		input = readline("\033[0;32mdish-0.9\033[0m$ ");
		if (!input)
			raise_exit();
		ptree = parse_input(input, env);
		if (ptree)
		{
			substitute_command_tree(ptree, env);
			((t_token *)ptree->content)->type |= HEAD;
			g_exit_status = execute(ptree, env);
			set_signal_handler();
			del_heredoc_tmp_files(ptree);
			ft_treeclear(&ptree, del_token);
		}
		free(input);
	}
	ft_lstclear(&env, del_str_pair);
}
