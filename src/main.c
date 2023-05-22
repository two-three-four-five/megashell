/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 15:51:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/command.h"
#include "type.h"
#include "shell/signal.h"
#include "shell/input.h"
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
		ptree = parse_input(input, env);
		if (!ptree)
		{
			free(input);
			continue ;
		}
		add_history(input);
		substitute_command_tree(ptree, env);
		printf("%10s", "head |");
		((t_token *)ptree->content)->type |= HEAD;
		print_tree(ptree);
		printf("$?: %d\n", execute(ptree, env));
		set_signal_handler();
		ft_treeclear(&ptree, del_token);
		free(input);
	}
	ft_lstclear(&env, del_str_pair);
	printf("exit\n");
	return (0);
}
