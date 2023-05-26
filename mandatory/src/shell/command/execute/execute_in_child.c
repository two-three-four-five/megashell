/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_in_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:47:06 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 14:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell/command.h"
#include "type.h"

int	execute_in_child(t_tree *tree, t_dict *env)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	return (execute(tree, env));
}
