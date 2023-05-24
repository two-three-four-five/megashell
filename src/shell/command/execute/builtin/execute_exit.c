/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:38:05 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 23:21:59 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell.h"

#define TOO_MANY_ARGUMENTS 1
#define NUMERIC_ARGUMENT_REQUIRED 2

static long long	ft_atoll(char *str);
static t_bool		is_nondigit_contained(char *arg);
static t_bool		is_numeric_argument(char *arg);
static void			raise_exit_error(int errno, char *arg);

int	execute_exit(t_tree *tree, t_dict *env)
{
	t_token	*token;

	(void)env;
	if (!tree->left)
		exit(g_exit_status);
	tree = tree->left;
	token = tree->content;
	if (!is_numeric_argument(token->token))
		raise_exit_error(NUMERIC_ARGUMENT_REQUIRED, token->token);
	else
	{
		if (tree->left)
		{
			raise_exit_error(TOO_MANY_ARGUMENTS, token->token);
			return (127);
		}
		else
			exit(ft_atoll(token->token));
	}
	return (1);
}

static long long	ft_atoll(char *str)
{
	int					sign;
	unsigned long long	result;
	unsigned long long	pre_result;
	long long			ret;

	sign = 1;
	result = 0;
	pre_result = 0;
	if (*str == '+' || *str == '-')
		sign = *str++ - 44;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		if (result / 10 != pre_result)
			return (-1);
		pre_result = result;
	}
	ret = sign * result;
	if ((unsigned long long)(ret * sign) == result)
		return (sign * result);
	else
		return (-1);
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

static void	raise_exit_error(int errno, char *arg)
{
	if (errno == TOO_MANY_ARGUMENTS)
		ft_putendl_fd("dish: exit: too many arguments", 2);
	else if (errno == NUMERIC_ARGUMENT_REQUIRED)
	{
		ft_putstr_fd("dish: exit: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(2);
	}
}
