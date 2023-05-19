/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_command_tree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:35:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/19 16:31:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_bool	has_slash(char *token);
static t_bool	is_builtin_cmd(char *token);
static char		*search_command_token(char *token, t_dict *env);
void			substitute_command_tree(t_tree *ptree, t_dict *env);

void	substitute_command_tree(t_tree *ptree, t_dict *env)
{
	char	type;
	char	*cmd;
	char	*new_cmd;

	if (!ptree)
		return ;
	type = ((t_token *)ptree->content)->type;
	cmd = ((t_token *)ptree->content)->token;
	if (type == CMD && !has_slash(cmd) && !is_builtin_cmd(cmd) && *cmd)
	{
		new_cmd = search_command_token(cmd, env);
		if (new_cmd)
		{
			free(cmd);
			((t_token *)ptree->content)->token = new_cmd;
		}
	}
	substitute_command_tree(ptree->left, env);
	substitute_command_tree(ptree->right, env);
}

static t_bool	has_slash(char *token)
{
	while (*token)
	{
		if (*token == '/')
			return (TRUE);
		token++;
	}
	return (FALSE);
}

static t_bool	is_builtin_cmd(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "cd"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "pwd"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "export"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "unset"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "env"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "exit"))
		return (TRUE);
	else
		return (FALSE);
}

static char	*join_path_and_command(char *path, char *token)
{
	char	*ret;
	char	*temp;

	temp = ft_strjoin(path, "/");
	if (!temp)
		return (NULL);
	ret = ft_strjoin(temp, token);
	free(temp);
	return (ret);
}

static char	*search_command_token(char *token, t_dict *env)
{
	t_list	*path;
	t_list	*curr;
	char	*cmd;
	int		fd;

	path = split_path(get_dict_value(env, "PATH"));
	if (!path)
		return (NULL);
	curr = path;
	while (curr)
	{
		cmd = join_path_and_command(curr->content, token);
		fd = open(cmd, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			ft_lstclear(&path, free);
			return (cmd);
		}
		free(cmd);
		curr = curr->next;
	}
	ft_lstclear(&path, free);
	return (NULL);
}
