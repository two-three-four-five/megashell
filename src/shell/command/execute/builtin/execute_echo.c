/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:07:02 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 21:16:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "shell.h"
#include "type.h"

static t_bool	is_valid_n_option(char *arg);

int	execute_echo(t_tree *tree, t_dict *env)
{
	t_bool	is_n_option_exist;
	char	**argv;
	int		idx;

	(void)env;
	argv = get_argv(tree);
	is_n_option_exist = FALSE;
	idx = 0;
	while (argv[++idx])
	{
		if (is_valid_n_option(argv[idx]))
			is_n_option_exist = TRUE;
		else
			break ;
	}
	while (argv[idx])
	{
		printf("%s", argv[idx++]);
		if (argv[idx])
			printf(" ");
	}
	if (!is_n_option_exist)
		printf("\n");
	del_strp(argv);
	return (0);
}

static t_bool	is_valid_n_option(char *arg)
{
	if (*arg != '-')
		return (FALSE);
	while (*(++arg))
	{
		if (*arg != 'n')
			return (FALSE);
	}
	return (TRUE);
}
