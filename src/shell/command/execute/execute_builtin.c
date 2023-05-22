/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:09:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 20:18:52 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "type.h"

int	execute_builtin(t_tree *tree, t_dict *env)
{
	(void)tree;
	(void)env;
	exit(0);
}
