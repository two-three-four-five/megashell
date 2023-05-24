/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_or_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:18:59 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/24 18:59:17 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell/command.h"
#include "shell/input.h"
#include "type.h"

int	execute_or_if(t_tree *tree, t_dict *env)
{
	int		exit_status;

	if (((t_token *)tree->content)->type & _HEAD)
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
