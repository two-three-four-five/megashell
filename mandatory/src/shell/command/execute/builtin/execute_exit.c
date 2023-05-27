/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:38:05 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/27 21:58:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

static t_bool		is_nondigit_contained(char *arg);
static t_bool		is_numeric_argument(char *arg);
static int			_execute_exit(t_tree *tree, t_dict *env);
int					execute_exit(t_tree *tree, t_dict *env);

int	execute_exit(t_tree *tree, t_dict *env)
{
	t_token	*token;

	token = tree->content;
	if ((token->type & _REALHEAD) == _REALHEAD)
		ft_putendl_fd("exit", 1);
	return (_execute_exit(tree, env));
}

static int	_execute_exit(t_tree *tree, t_dict *env)
{
	t_token	*token;

	(void)env;
	if (!tree->left)
		exit(g_exit_status);
	token = tree->left->content;
	if (!is_numeric_argument(token->token))
		raise_exit_error(NUMERIC_ARGUMENT_REQUIRED, token->token);
	else
	{
		if (tree->left->left)
		{
			raise_exit_error(TOO_MANY_ARGUMENTS, token->token);
			return (1);
		}
		else
			exit(ft_atoll(token->token));
	}
	return (1);
}

static t_bool	is_nondigit_contained(char *arg)
{
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (TRUE);
		arg++;
	}
	return (FALSE);
}

static t_bool	is_numeric_argument(char *arg)
{
	long long	numeric_argument;

	numeric_argument = ft_atoll(arg);
	if (is_nondigit_contained(arg))
		return (FALSE);
	else if (ft_strlen(arg) > 2 && numeric_argument == -1)
		return (FALSE);
	else
		return (TRUE);
}
