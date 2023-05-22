/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:51:43 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 14:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "type.h"
#include "shell/parse.h"
#include "shell/command.h"
#include "shell/signal.h"

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int	execute(t_tree *node, t_dict *env)
{
	const t_token	*token = node->content;

	if (token->type & HEAD)
		signal(SIGINT, handle_sigint_in_execution);
	if ((token->type & (~HEAD)) == CMD)
		return (execute_cmd(node, env));
	else if ((token->type & (~HEAD)) == PIPE)
		return (execute_pipe(node, env));
	else if ((token->type & (~HEAD)) == SUBSHELL)
		return (execute_subshell(node, env));
	else if ((token->type & (~HEAD)) == AND_IF)
		return (execute_and_if(node, env));
	else if ((token->type & (~HEAD)) == OR_IF)
		return (execute_or_if(node, env));
	return (0);
}