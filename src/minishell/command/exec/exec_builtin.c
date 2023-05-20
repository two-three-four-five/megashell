/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:09:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 15:35:19 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"

int	exec_builtin(t_tree *node, t_dict *env)
{
	(void)env;
	(void) node;
	exit (0);
}
