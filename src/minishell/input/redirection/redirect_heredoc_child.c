/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc_child.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:52:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 00:00:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/parse.h"
#include "shell/signal.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

static void	execute_heredoc(char *eof, int *line);
static void	raise_eof_warning(char *eof, int *line);
void		redirect_heredoc_child(t_list *lst);

void	redirect_heredoc_child(t_list *lst)
{
	static int	line;

	signal(SIGINT, SIG_DFL);
	lst = lst->next;
	while (lst)
	{
		if (((t_token *)lst->content)->type == DLESS)
			execute_heredoc(((t_token *)lst->next->content)->token, &line);
		lst = lst->next;
	}
	exit(0);
}

static void	execute_heredoc(char *eof, int *line)
{
	static int	file;
	char		*input;

	file++;
	while (TRUE)
	{
		input = readline("> ");
		(*line)++;
		if (!input)
		{
			raise_eof_warning(eof, line);
			return ;
		}
		else if (!ft_strncmp(eof, input, ft_strlen(eof)))
			return ;
		else
		{
			file = open(".hello", O_WRONLY | O_APPEND | O_CREAT, 0644);
			ft_putendl_fd(input, file);
			close(file);
		}
	}
}

static void	raise_eof_warning(char *eof, int *line)
{
	ft_putstr_fd("dish: warning: here-document at line ", 2);
	ft_putnbr_fd(*line, 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(eof, 2);
	ft_putendl_fd("\')", 2);
}
