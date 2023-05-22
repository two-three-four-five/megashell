/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 02:52:55 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 16:31:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "shell/error.h"
#include "shell/input.h"
#include "type.h"

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

static int	check_file(char *filename, int type)
{
	if (filename[0] == '$')
		return (AMBIGUOUS_REDIRECT);
	else if (type & REDIRECT_OUT)
	{
		if (is_directory(filename))
			return (IS_A_DIRECTORY);
		else if (access(filename, F_OK) == 0 && access(filename, W_OK) != 0)
			return (PERMISSION_DENIED);
	}
	else if (!(type & REDIRECT_OUT))
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

static int	open_file(char *filename, int type)
{
	int	fd;
	int	errno;

	errno = check_file(filename, type);
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
		fd = open_file(((t_token *)tree->left->content)->token, type);
		if (fd < 0)
			return (-1);
		if (type & REDIRECT_OUT)
			dup2(fd, STDOUT_FILENO);
		else
			dup2(fd, STDIN_FILENO);
		tree = tree->right;
	}
	return (0);
}
