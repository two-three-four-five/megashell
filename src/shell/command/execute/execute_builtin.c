/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:09:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 16:26:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/command.h"
#include "shell/envp.h"
#include "type.h"

int	execute_builtin(t_tree *tree, t_dict *env)
{
	char	**argv;
	char	**envp;

	argv = get_argv(tree);
	envp = get_envp(env);

	// Do Something

	del_strp(argv);
	del_strp(envp);
	exit (0);
}
