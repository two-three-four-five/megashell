/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:30:41 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 11:23:01 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>

static int	ft_wifexited(int status);
static int	ft_wexitstatus(int status);
static int	ft_wtermsig(int status);
static int	ft_wifsignaled(int status);

int	get_exit_status(int status)
{
	if (ft_wifexited(status))
		return (ft_wexitstatus(status));
	else if (ft_wifsignaled(status))
	{
		if (ft_wtermsig(status) == SIGQUIT)
			printf("Quit: 3\n");
		return (ft_wtermsig(status) + 128);
	}
	else
		return (-1);
}

static int	ft_wifexited(int status)
{
	int	w_int;
	int	w_status;

	w_int = (*(int *)&(status));
	w_status = w_int & 0177;
	return (w_status == 0);
}

static int	ft_wifsignaled(int status)
{
	int	w_int;
	int	w_status;

	w_int = (*(int *)&(status));
	w_status = w_int & 0177;
	return (w_status != 0177 && w_status != 0);
}

static int	ft_wtermsig(int status)
{
	int	w_int;
	int	w_status;

	w_int = (*(int *)&(status));
	w_status = w_int & 0177;
	return (w_status);
}

static int	ft_wexitstatus(int status)
{
	int	w_int;

	w_int = (*(int *)&(status));
	return ((w_int >> 8) & 0x000000ff);
}
