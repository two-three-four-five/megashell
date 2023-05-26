/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_or_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:18:59 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 19:49:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell/command.h"
#include "shell/input.h"
#include "type.h"

int	execute_or_if(t_tree *tree, t_dict *env)
{
	int		exit_status;

	if ((((t_token *)tree->content)->type & _REALHEAD) == _REALHEAD)
	{
		((t_token *)tree->left->content)->type |= _REALHEAD;
		((t_token *)tree->right->content)->type |= _REALHEAD;
	}
	else if (((t_token *)tree->content)->type & _HEAD)
	{
		((t_token *)tree->left->content)->type |= _HEAD;
		((t_token *)tree->right->content)->type |= _HEAD;
	}
	exit_status = execute(tree->left, env);
	if (exit_status != 0)
		exit_status = execute(tree->right, env);
	if (((t_token *)tree->content)->type & _HEAD)
		return (exit_status);
	else
		exit(exit_status);
	return (0);
}
