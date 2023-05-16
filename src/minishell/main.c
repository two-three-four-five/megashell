/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/16 21:49:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_dict		*env;

	if (!check_arg(argc, argv))
	{
		printf("usage : ./minishell\n");
		return (1);
	}
	env = get_envp_dict(envp);
	set_signal_handler();
	while (TRUE)
	{
		input = readline("dish-0.2$ ");
		if (!input)
			break ;
		analyze_input(input, env);
		add_history(input);
		free(input);
	}
	ft_lstclear(&env, del_str_pair);
	printf("exit\n");
	return (0);
}
