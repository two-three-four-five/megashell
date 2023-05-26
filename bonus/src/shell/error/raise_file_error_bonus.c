/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_file_error_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:05:39 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/error_bonus.h"

void	raise_file_error(int errno, char *filename)
{
	ft_putstr_fd(MSG_DISH, 2);
	if (errno == NO_SUCH_FILE_OR_DIRECTORY)
	{
		ft_putstr_fd(filename, 2);
		ft_putendl_fd(MSG_NO_SUCH_FILE_OR_DIRECTORY, 2);
	}
	else if (errno == IS_A_DIRECTORY)
	{
		ft_putstr_fd(filename, 2);
		ft_putendl_fd(MSG_IS_A_DIRECTORY, 2);
	}
	else if (errno == PERMISSION_DENIED)
	{
		ft_putstr_fd(filename, 2);
		ft_putendl_fd(MSG_PERMISSION_DENIED, 2);
	}
	else if (errno == AMBIGUOUS_REDIRECT)
	{
		ft_putstr_fd(filename, 2);
		ft_putendl_fd(MSG_AMBIGUOUS_REDIRECT, 2);
	}
}
