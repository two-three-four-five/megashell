/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:09:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 20:57:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "type.h"

int	execute_builtin(t_tree *tree, t_dict *env)
{
	t_token	*token;

	token = tree->content;
	if (ft_strcmp(token->token, "unset") == 0)
		return (execute_unset(tree, env));
	exit(0);
}
