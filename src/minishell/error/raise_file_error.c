/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_file_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:05:39 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/21 03:09:19 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/error.h"
#include "libft.h"

void	raise_file_error(int errno, char *filename)
{
	if (errno == NO_SUCH_FILE_OR_DIRECTORY)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (errno == IS_A_DIRECTORY)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putendl_fd(": Is a directory", 2);
	}
	else if (errno == PERMISSION_DENIED)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	else if (errno == AMBIGUOUS_REDIRECT)
	{
		ft_putstr_fd("dish: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putendl_fd(": ambiguous redirect", 2);
	}
}
