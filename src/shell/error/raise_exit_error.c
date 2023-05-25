/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_exit_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:55:42 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/25 23:58:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/error.h"

void	raise_exit_error(int errno, char *arg)
{
	ft_putendl_fd("exit", 2);
	if (errno == TOO_MANY_ARGUMENTS)
		ft_putendl_fd("dish: exit: too many arguments", 2);
	else if (errno == NUMERIC_ARGUMENT_REQUIRED)
	{
		ft_putstr_fd("dish: exit: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(2);
	}
}
