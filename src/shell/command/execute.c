/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:51:43 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/24 01:44:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell/command.h"
#include "shell/input.h"
#include "shell/signal.h"
#include "type.h"

int	execute(t_tree *node, t_dict *env)
{
	const t_token	*token = node->content;

	if (token->type & _HEAD)
		signal(SIGINT, handle_sigint_in_execution);
	if ((token->type & (~_HEAD)) == CMD)
		return (execute_cmd(node, env));
	else if ((token->type & (~_HEAD)) == PIPE)
		return (execute_pipe(node, env));
	else if ((token->type & (~_HEAD)) == _SUBSHELL)
		return (execute_subshell(node, env));
	else if ((token->type & (~_HEAD)) == AND_IF)
		return (execute_and_if(node, env));
	else if ((token->type & (~_HEAD)) == OR_IF)
		return (execute_or_if(node, env));
	return (0);
}
