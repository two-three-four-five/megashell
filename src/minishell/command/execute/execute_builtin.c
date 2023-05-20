/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:09:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/21 00:30:07 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/command.h"
#include "shell/envp.h"
#include "shell/type.h"

int	execute_builtin(t_tree *tree, t_dict *env)
{
	char	**argv;
	char	**envp;

	argv = get_argv(tree);
	envp = get_envp(env);

	// Do Something

	free_strp(argv);
	free_strp(envp);
	exit (0);
}
