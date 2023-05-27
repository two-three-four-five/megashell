/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_command_tree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:35:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/28 01:01:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "shell/command.h"
#include "shell/input.h"
#include "type.h"

static t_bool	has_slash(char *token);
static char		*search_command_token(char *token, t_dict *env);
static char		*join_path_and_command(char *path, char *token);
static t_list	*split_path(char *path);
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

static char	*search_command_token(char *token, t_dict *env)
{
	t_list	*path;
	t_list	*curr;
	char	*cmd;

	path = split_path(get_dict_value(env->next, "PATH"));
	if (!path)
		return (NULL);
	curr = path;
	while (curr)
	{
		cmd = join_path_and_command(curr->content, token);
		if (access(cmd, X_OK) == 0 && !is_directory(cmd))
		{
			ft_lstclear(&path, free);
			return (cmd);
		}
		free(cmd);
		curr = curr->next;
	}
	ft_lstclear(&path, free);
	return (NULL);
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

static t_list	*split_path(char *path)
{
	t_list	*head;
	t_list	*node;
	int		i;
	int		len;

	if (!path)
		return (NULL);
	head = NULL;
	i = 0;
	while (path[i])
	{
		len = 0;
		while (path[i + len] != ':' && path[i + len] != '\0')
			len++;
		node = ft_lstnew(ft_substr(path, i, len));
		if (!node || !node->content)
			exit(1);
		ft_lstadd_back(&head, node);
		while (path[i] != ':' && path[i] != '\0')
			i++;
		if (path[i] == ':')
			i++;
	}
	return (head);
}
