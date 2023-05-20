/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/20 15:35:59 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/command.h"
#include "shell/type.h"
#include "shell/signal.h"
#include "shell/parse.h"
#include "shell/envp.h"

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

static t_bool	check_arg(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		return (TRUE);
	else
		return (FALSE);
}

void	print_string(void *ptr)
{
	printf("%s\n", (char *)ptr);
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_dict		*env;
	t_tree		*ptree;

	if (!check_arg(argc, argv))
	{
		printf("usage : ./minishell\n");
		return (1);
	}
	env = get_envp_dict(envp);
	set_signal_handler();
	while (TRUE)
	{
		input = readline("dish-0.5$ ");
		if (!input)
			break ;
		add_history(input);
		ptree = parse_input(input, env);
		if (!ptree)
		{
			free(input);
			continue ;
		}
		substitute_command_tree(ptree, env);
		printf("%10s", "head |");
		print_tree(ptree);
		execute(ptree, env);
		ft_treeclear(&ptree, del_token);
		free(input);
	}
	ft_lstclear(&env, del_str_pair);
	printf("exit\n");
	return (0);
}
