/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:51:43 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell/command_bonus.h"
#include "shell/input_bonus.h"
#include "shell/signal_bonus.h"
#include "type_bonus.h"

int	execute(t_tree *node, t_dict *env)
{
	const t_token	*token = node->content;

	if ((token->type & (~_REALHEAD)) & _CMD)
		return (execute_cmd(node, env));
	else if ((token->type & (~_REALHEAD)) == PIPE)
		return (execute_pipe(node, env));
	else if ((token->type & (~_REALHEAD)) == _SUBSHELL)
		return (execute_subshell(node, env));
	else if ((token->type & (~_REALHEAD)) == AND_IF)
		return (execute_and_if(node, env));
	else if ((token->type & (~_REALHEAD)) == OR_IF)
		return (execute_or_if(node, env));
	return (0);
}
