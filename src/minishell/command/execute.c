/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:51:43 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 17:23:53 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "shell/type.h"
#include "shell/parse.h"
#include "shell/command.h"

int	execute(t_tree *node, t_dict *env)
{
	const t_token	*token = node->content;

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
