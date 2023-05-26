/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_heredoc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:00:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type_bonus.h"
#include "shell_bonus.h"
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

static int	ft_wifsignaled(int status);

t_bool	wait_heredoc(pid_t pid, t_list *lst, char *filename, int fd)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, handle_sigint);
	if (ft_wifsignaled(status))
	{
		g_exit_status = get_exit_status(status);
		ft_putendl_fd("", 1);
		if (unlink(filename))
			exit(1);
		free(filename);
		close(fd);
		return (FALSE);
	}
	else
	{
		free(((t_token *)lst->next->content)->token);
		((t_token *)lst->next->content)->token = filename;
		close(fd);
		return (TRUE);
	}
}

static int	ft_wifsignaled(int status)
{
	int	w_int;
	int	w_status;

	w_int = (*(int *)&(status));
	w_status = w_int & 0177;
	return (w_status != 0177 && w_status != 0);
}
