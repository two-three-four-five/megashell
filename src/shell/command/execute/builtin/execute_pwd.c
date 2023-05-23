/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:50:45 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 15:24:10 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "shell.h"
#include "type.h"

int	execute_pwd(t_tree *tree, t_dict *env)
{
	char	*current_pwd;
	char	*arg;

	(void) env;
	if (tree->left)
	{
		arg = ((t_token *)tree->left->content)->token;
		if (ft_strlen(arg) > 1 && arg[0] == '-')
		{
			ft_putstr_fd("bash: pwd: ", 2);
			write(2, arg, 2);
			ft_putendl_fd(": invalid option", 2);
			ft_putendl_fd("pwd: usage: pwd", 2);
			return (2);
		}
	}
	current_pwd = getcwd(0, 0);
	printf("%s\n", current_pwd);
	free(current_pwd);
	return (0);
}
