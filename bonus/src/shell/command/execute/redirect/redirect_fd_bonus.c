/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 02:52:55 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "shell/error_bonus.h"
#include "shell/input_bonus.h"
#include "type_bonus.h"

static t_bool	is_directory(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (TRUE);
	}
	else
		return (FALSE);
}

static int	check_file(t_token *token, int type)
{
	char	*filename;

	filename = token->token;
	if (token->type == AMBIGUOUS)
		return (AMBIGUOUS_REDIRECT);
	else if (type & _REDIRECT_OUT)
	{
		if (ft_strlen(filename) == 0)
			return (NO_SUCH_FILE_OR_DIRECTORY);
		else if (is_directory(filename))
			return (IS_A_DIRECTORY);
		else if (access(filename, F_OK) == 0 && access(filename, W_OK) != 0)
			return (PERMISSION_DENIED);
	}
	else if (!(type & _REDIRECT_OUT))
	{
		if (access(filename, F_OK) != 0)
			return (NO_SUCH_FILE_OR_DIRECTORY);
		else if (access(filename, R_OK) != 0)
			return (PERMISSION_DENIED);
	}
	else
		return (0);
	return (0);
}

static int	open_file(t_token *token, int type)
{
	char	*filename;
	int		fd;
	int		errno;

	errno = check_file(token, type);
	filename = token->token;
	if (errno)
	{
		raise_file_error(errno, filename);
		return (-1);
	}
	if (type == LESS)
		fd = open(filename, O_RDONLY);
	else if (type == DLESS)
		fd = open(filename, O_RDONLY);
	else if (type == GREAT)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == DGREAT)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = -1;
	if (fd < 0)
		return (-1);
	return (fd);
}

int	redirect_fd(t_tree *tree)
{
	int	type;
	int	fd;

	tree = tree->right;
	while (tree)
	{
		type = ((t_token *)tree->content)->type;
		fd = open_file(tree->left->content, type);
		if (fd < 0)
			return (-1);
		if (type & _REDIRECT_OUT)
			dup2(fd, STDOUT_FILENO);
		else
			dup2(fd, STDIN_FILENO);
		tree = tree->right;
	}
	return (0);
}
