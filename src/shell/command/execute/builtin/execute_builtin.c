/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:09:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 20:37:39 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "type.h"

int	execute_builtin(t_tree *tree, t_dict *env)
{
	t_token	*token;

	token = tree->content;
	if (ft_strcmp(token->token, "echo") == 0)
		return (execute_echo(tree, env));
	else if (ft_strcmp(token->token, "exit") == 0)
		return (execute_exit(tree, env));

	exit (0);
}
