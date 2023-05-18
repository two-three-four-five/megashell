/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_command_tree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:35:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/18 15:41:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_bool	has_slash(char *token);
static t_bool	is_builtin_token(char *token);
static char		*search_command_token(char *token, t_dict *env);
void			substitute_command_tree(t_tree *ptree, t_dict *env);

void	substitute_command_tree(t_tree *ptree, t_dict *env)
{
	char	*cmd;

	if (!ptree)
		return ;
	else if (((t_token *)ptree->content)->type == CMD && \
			!has_slash(((t_token *)ptree->content)->token) && \
			!is_builtin_token(((t_token *)ptree->content)->token))
	{
		cmd = search_command_token(((t_token *)ptree->content)->token, env);
		if (cmd)
		{
			free(((t_token *)ptree->content)->token);
			((t_token *)ptree->content)->token = cmd;
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

static t_bool	is_builtin_token(char *token)
{
	if (!ft_strcmp(token, "echo"))
		return (TRUE);
	else if (!ft_strcmp(token, "cd"))
		return (TRUE);
	else if (!ft_strcmp(token, "pwd"))
		return (TRUE);
	else if (!ft_strcmp(token, "export"))
		return (TRUE);
	else if (!ft_strcmp(token, "unset"))
		return (TRUE);
	else if (!ft_strcmp(token, "env"))
		return (TRUE);
	else if (!ft_strcmp(token, "exit"))
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
