/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:00:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 21:04:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/signal.h"
#include "shell/parse.h"
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

t_bool	wait_heredoc(pid_t pid, t_list *lst, char *filename, int fd)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	signal(SIGINT, handle_sigint);
	if (WIFSIGNALED(status))
	{
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