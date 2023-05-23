/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:07:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 21:17:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"

static int	raise_env_usage_error(void);

int	execute_env(t_tree *tree, t_dict *env)
{
	if (tree->left)
		return (raise_env_usage_error());
	ft_lstiter(env->next, print_str_pair);
	return (0);
}

static int	raise_env_usage_error(void)
{
	ft_putendl_fd("usage: env", 2);
	return (1);
}
