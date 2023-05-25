/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_cd_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:52:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/25 23:54:20 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/error.h"

int	raise_cd_error(int errno, char *arg)
{
	ft_putstr_fd(MSG_DISH, 2);
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
		ft_putendl_fd("cd: too many arguments", 2);
	else if (errno == HOME_NOT_SET)
		ft_putendl_fd("cd: HOME not set", 2);
	else if (errno == OLDPWD_NOT_SET)
		ft_putendl_fd("cd: OLDPWD not set", 2);
	return (1);
}
