/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:11:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 01:51:28 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/parse.h"
#include "shell/signal.h"

#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

static void		set_tempfile(char **filename, int *fd);
static t_bool	heredoc_parent(pid_t pid, t_list *lst, char *filename, int fd);
static void		heredoc_child(char *eof, int fd);
t_bool			redirect_heredoc(t_list *lst);

t_bool	redirect_heredoc(t_list *lst)
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
				code = heredoc_parent(pid, lst, filename, fd);
			else if (pid == 0)
				heredoc_child(((t_token *)lst->next->content)->token, fd);
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

static t_bool	heredoc_parent(pid_t pid, t_list *lst, char *filename, int fd)
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

static void	heredoc_child(char *eof, int fd)
{
	static int	line;
	char		*input;

	signal(SIGINT, SIG_DFL);
	while (TRUE)
	{
		input = readline("> ");
		line++;
		if (!input)
		{
			ft_putstr_fd("dish: warning: here-document at line ", 2);
			ft_putnbr_fd(line, 2);
			ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
			ft_putstr_fd(eof, 2);
			ft_putendl_fd("\')", 2);
			break ;
		}
		else if (!ft_strncmp(eof, input, ft_strlen(eof)) && \
				!ft_strncmp(eof, input, ft_strlen(input)))
			break ;
		else
			ft_putendl_fd(input, fd);
	}
	exit(0);
}
