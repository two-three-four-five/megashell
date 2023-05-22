/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:58:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 14:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/parse.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

static void		raise_warning(int line, char *eof);
static t_bool	check_delimiter(char *input, char *eof);
static void		ft_putendl_fd_after_expand(char *str, int fd, t_dict *env);
void			exec_heredoc(char *eof, int fd, t_dict *env);

void	exec_heredoc(char *eof, int fd, t_dict *env)
{
	static int	line;
	char		*input;
	int			quote;

	quote = count_quote(eof);
	signal(SIGINT, SIG_DFL);
	while (TRUE)
	{
		input = readline("> ");
		line++;
		if (!input)
		{
			raise_warning(line, eof);
			break ;
		}
		else if (check_delimiter(input, eof))
			break ;
		else if (quote)
			ft_putendl_fd(input, fd);
		else
			ft_putendl_fd_after_expand(input, fd, env);
	}
	exit(0);
}

static void	raise_warning(int line, char *eof)
{
	char	*delimiter;

	delimiter = remove_quote_token(eof);
	ft_putstr_fd("dish: warning: here-document at line ", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	if (delimiter)
		ft_putstr_fd(delimiter, 2);
	else
		ft_putstr_fd(eof, 2);
	ft_putendl_fd("\')", 2);
	if (delimiter)
		free(delimiter);
}

static t_bool	check_delimiter(char *input, char *eof)
{
	char	*delimiter;
	t_bool	ret;

	delimiter = remove_quote_token(eof);
	if (!delimiter)
		return (TRUE);
	if (!ft_strcmp(input, delimiter))
		ret = TRUE;
	else
		ret = FALSE;
	free(delimiter);
	return (ret);
}

static void	ft_putendl_fd_after_expand(char *str, int fd, t_dict *env)
{
	char	*expansion;

	expansion = expand_parameter_token(str, env);
	if (expansion)
	{
		ft_putendl_fd(expansion, fd);
		free(expansion);
	}
	else
		ft_putendl_fd(str, fd);
}
