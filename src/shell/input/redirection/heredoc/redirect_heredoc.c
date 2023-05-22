/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:11:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 21:03:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/parse.h"
#include "shell/signal.h"
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

static void		set_tempfile(char **filename, int *fd);
t_bool			redirect_heredoc(t_list *lst, t_dict *env);

t_bool	redirect_heredoc(t_list *lst, t_dict *env)
{
	pid_t	pid;
	char	*filename;
	int		fd;
	t_bool	code;

	while (lst)
	{
		if (((t_token *)lst->content)->type == DLESS)
		{
			set_tempfile(&filename, &fd);
			if (fd < 0)
				exit(1);
			pid = fork();
			if (pid > 0)
				code = wait_heredoc(pid, lst, filename, fd);
			else if (pid == 0)
				exec_heredoc(((t_token *)lst->next->content)->token, fd, env);
			else
				exit(1);
			if (!code)
				return (FALSE);
		}
		lst = lst->next;
	}
	return (TRUE);
}

static void	set_tempfile(char **filename, int *fd)
{
	static int	num;
	char		*name;
	char		*num_str;
	int			tmp_fd;

	while (TRUE)
	{
		num++;
		num_str = ft_itoa(num);
		name = ft_strjoin(".temp_", num_str);
		free(num_str);
		tmp_fd = open(name, O_RDONLY);
		if (tmp_fd > 0)
		{
			free(name);
			close(tmp_fd);
			continue ;
		}
		else
			break ;
	}
	*filename = name;
	*fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0644);
}
