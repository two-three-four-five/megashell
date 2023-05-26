/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/25 23:21:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "shell.h"
#include "type.h"

int				g_exit_status;

static t_bool	check_arg(int argc, char **argv);
static void		print_ascii_dish(void);
static void		print_ascii_developers(void);
int				main(int argc, char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	if (!check_arg(argc, argv))
	{
		printf("usage : ./minishell\n");
		return (1);
	}
	print_ascii_dish();
	print_ascii_developers();
	g_exit_status = 0;
	set_signal_handler();
	execute_shell(envp);
	return (0);
}

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
	RED"      ___          "YEL"             "\
	GRN"___           "BLU"___     "\
	RED"\n     /\\  \\     "YEL"     ___      "\
	GRN"  /\\  \\         "BLU"/\\__\\    "\
	RED"\n    /::\\  \\    "YEL"    /\\  \\   "\
	GRN"   /::\\  \\       "BLU"/:/  /    "\
	RED"\n   /:/\\:\\  \\  "YEL"     \\:\\  \\"\
	GRN"    /:/\\ \\  \\     "BLU"/:/__/     "\
	RED"\n  /:/  \\:\\__\\ "YEL"     /::\\__\\"\
	GRN"  _\\:\\~\\ \\  \\   "BLU"/::\\  \\ ___ "\
	RED"\n /:/__/ \\:|__|  "YEL"__/:/\\/__/ "\
	GRN"/\\ \\:\\ \\ \\__\\ "BLU"/:/\\:\\  /\\__\\"\
	RED"\n \\:\\  \\ /:/  /"YEL" /\\/:/  /    "\
	GRN"\\:\\ \\:\\ \\/__/ "BLU"\\/__\\:\\/:/  /"\
	RED"\n  \\:\\  /:/  /  "YEL"\\::/__/      "\
	GRN"\\:\\ \\:\\__\\        "BLU"\\::/  / "\
	RED"\n   \\:\\/:/  /   "YEL" \\:\\__\\    "\
	GRN"   \\:\\/:/  /        "BLU"/:/  /  "\
	RED"\n    \\::/__/     "YEL" \\/__/       "\
	GRN" \\::/  /        "BLU"/:/  /   "\
	RED"\n     ~~          "YEL"              "\
	GRN"\\/__/         "BLU"\\/__/    "BOLD"1.2.5"END);
}

static void	print_ascii_developers(void)
{
	printf(\
	"\n        _                             ___"\
	"\n|_     | \\ _  _  _|   _| _    () ()    |  _ _|_. _ _         "\
	"\n|_)\\/  |_/(_|| |(_|\\/(_|(_|\\/ (_X(_X  _|_| | | |(_(_)\\/      "\
	"\n   /               /       /                         /       "\
	"\n");
}
