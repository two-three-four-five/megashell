/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:03:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 13:57:17 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include "libft.h"
#include "type.h"

static int	raise_cd_error(int errno, char *arg);
static int	chdir_to_oldpwd(t_dict *env);

int	execute_cd(t_tree *tree, t_dict *env)
{
	t_token	*token;

	(void)env;
	if (ft_treeleftsize(tree) == 1)
	{
		if (!get_dict_value(env->next, "HOME"))
			return (raise_cd_error(HOME_NOT_SET, NULL));
		else
			return (chdir(get_dict_value(env->next, "HOME")));
	}
	token = tree->left->content;
	if (ft_treeleftsize(tree) > 2)
		return (raise_cd_error(TOO_MANY_ARGUMENTS, NULL));
	if (ft_strcmp(token->token, "-") == 0)
		return (chdir_to_oldpwd(env));
	else if (!is_file_exist(token->token))
		return (raise_cd_error(NO_SUCH_FILE_OR_DIRECTORY, token->token));
	else if (!is_directory(token->token))
		return (raise_cd_error(NOT_A_DIRECTORY, token->token));
	else if (!is_executable(token->token))
		return (raise_cd_error(PERMISSION_DENIED, token->token));
	reassign_dict_value(env->next, "OLDPWD", getcwd(0, 0));
	chdir(token->token);
	reassign_dict_value(env->next, "PWD", getcwd(0, 0));
	return (0);
}

static int	raise_cd_error(int errno, char *arg)
{
	if (errno == NO_SUCH_FILE_OR_DIRECTORY)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (errno == NOT_A_DIRECTORY)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": Not a directory", 2);
	}
	else if (errno == PERMISSION_DENIED)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	else if (errno == TOO_MANY_ARGUMENTS)
		ft_putendl_fd("dish: cd: too many arguments", 2);
	else if (errno == HOME_NOT_SET)
		ft_putendl_fd("dish: cd: HOME not set", 2);
	else if (errno == OLDPWD_NOT_SET)
		ft_putendl_fd("dish: cd: OLDPWD not set", 2);
	return (1);
}

static int	chdir_to_oldpwd(t_dict *env)
{
	char	*oldpwd;

	oldpwd = get_dict_value(env->next, "OLDPWD");
	if (!oldpwd)
		return (raise_cd_error(OLDPWD_NOT_SET, NULL));
	else
	{
		printf("%s\n", oldpwd);
		reassign_dict_value(env->next, "OLDPWD", getcwd(0, 0));
		chdir(oldpwd);
		reassign_dict_value(env->next, "PWD", getcwd(0, 0));
		return (0);
	}
}
