/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/24 16:50:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "shell.h"
#include "type.h"

int	g_exit_status;

static t_bool	check_arg(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		return (TRUE);
	else
		return (FALSE);
}

static void	print_ascii_dish(void)
{
	printf(\
	"      ___                       ___           ___     "\
	"\n     /\\  \\          ___        /\\  \\         /\\__\\    "\
	"\n    /::\\  \\        /\\  \\      /::\\  \\       /:/  /    "\
	"\n   /:/\\:\\  \\       \\:\\  \\    /:/\\ \\  \\     /:/__/     "\
	"\n  /:/  \\:\\__\\      /::\\__\\  _\\:\\~\\ \\  \\   /::\\  \\ ___ "\
	"\n /:/__/ \\:|__|  __/:/\\/__/ /\\ \\:\\ \\ \\__\\ /:/\\:\\  /\\__\\"\
	"\n \\:\\  \\ /:/  / /\\/:/  /    \\:\\ \\:\\ \\/__/ \\/__\\:\\/:/  /"\
	"\n  \\:\\  /:/  /  \\::/__/      \\:\\ \\:\\__\\        \\::/  / "\
	"\n   \\:\\/:/  /    \\:\\__\\       \\:\\/:/  /        /:/  /  "\
	"\n    \\::/__/      \\/__/        \\::/  /        /:/  /   "\
	"\n     ~~                        \\/__/         \\/__/    1.2.5");
	printf(\
	"\n        _                             ___"\
	"\n|_     | \\ _  _  _|   _| _    () ()    |  _ _|_. _ _         "\
	"\n|_)\\/  |_/(_|| |(_|\\/(_|(_|\\/ (_X(_X  _|_| | | |(_(_)\\/      "\
	"\n   /               /       /                         /       "\
	"\n");
}

int	main(int argc, char **argv, char **envp)
{
	if (!check_arg(argc, argv))
	{
		printf("usage : ./minishell\n");
		return (1);
	}
	print_ascii_dish();
	g_exit_status = 0;
	set_signal_handler();
	execute_shell(envp);
	return (0);
}
