/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_echo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:07:02 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "shell_bonus.h"
#include "type_bonus.h"

static t_bool	is_valid_n_option(char *arg);

int	execute_echo(t_tree *tree, t_dict *env)
{
	t_bool	is_n_option_exist;

	(void)env;
	is_n_option_exist = FALSE;
	tree = tree->left;
	while (tree)
	{
		if (is_valid_n_option(((t_token *)tree->content)->token))
			is_n_option_exist = TRUE;
		else
			break ;
		tree = tree->left;
	}
	while (tree)
	{
		printf("%s", ((t_token *)tree->content)->token);
		if (tree->left)
			printf(" ");
		tree = tree->left;
	}
	if (!is_n_option_exist)
		printf("\n");
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
