/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_cmd_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:20:05 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 09:32:21 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/error.h"

int	raise_cmd_error(int errno, char *cmd)
{
	if (errno == NO_SUCH_FILE_OR_DIRECTORY)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (127);
	}
	else if (errno == IS_A_DIRECTORY)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Is a directory", 2);
		return (126);
	}
	else if (errno == PERMISSION_DENIED)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Permission denied", 2);
		return (126);
	}
	else if (errno == COMMAND_NOT_FOUND)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
		return (127);
	}
	return (1);
}
