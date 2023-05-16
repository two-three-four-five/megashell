/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:11:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 00:01:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/parse.h"
#include "shell/signal.h"

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

static t_bool	has_heredoc(t_list *lst);

void	redirect_heredoc(t_list *lst)
{
	pid_t		pid;
	int			status;

	if (!has_heredoc(lst))
		return ;
	pid = fork();
	if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		signal(SIGINT, handle_sigint);
		ft_putendl_fd("", 1);
	}
	else if (pid == 0)
		redirect_heredoc_child(lst);
	else
	{
	}
}

static t_bool	has_heredoc(t_list *lst)
{
	lst = lst->next;
	while (lst)
	{
		if (((t_token *)lst->content)->type == DLESS)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}


