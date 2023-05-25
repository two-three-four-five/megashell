/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:03:25 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/25 23:53:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include "libft.h"
#include "type.h"

static int	chdir_to_oldpwd(t_tree *tree, t_dict *env);
int			execute_cd(t_tree *tree, t_dict *env);

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
		return (chdir_to_oldpwd(tree, env));
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

static int	chdir_to_oldpwd(t_tree *tree, t_dict *env)
{
	char	*oldpwd;

	(void) tree;
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
