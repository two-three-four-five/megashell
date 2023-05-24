/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_exit_in_parent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:19:31 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 23:25:07 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	execute_exit_in_parent(t_tree *tree, t_dict *env)
{
	ft_putendl_fd("exit", 2);
	return (execute_exit(tree, env));
}
