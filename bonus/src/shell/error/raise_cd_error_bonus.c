/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_cd_error_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:52:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/error_bonus.h"

int	raise_cd_error(int errno, char *arg)
{
	ft_putstr_fd(MSG_DISH, 2);
	ft_putstr_fd("cd: ", 2);
	if (errno == NO_SUCH_FILE_OR_DIRECTORY)
	{
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (errno == NOT_A_DIRECTORY)
	{
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": Not a directory", 2);
	}
	else if (errno == PERMISSION_DENIED)
	{
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	else if (errno == TOO_MANY_ARGUMENTS)
		ft_putendl_fd("too many arguments", 2);
	else if (errno == HOME_NOT_SET)
		ft_putendl_fd("HOME not set", 2);
	else if (errno == OLDPWD_NOT_SET)
		ft_putendl_fd("OLDPWD not set", 2);
	return (1);
}
