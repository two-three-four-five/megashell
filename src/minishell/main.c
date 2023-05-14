/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 21:14:16 by gyoon            ###   ########.fr       */
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
	t_list		*tokenized_lst;
	t_dict		*env;
	t_tree		*parse_tree;

	if (!check_arg(argc, argv))
	{
		printf("usage : ./minishell\n");
		return (1);
	}
	env = get_envp_dict(envp);
	ft_lstiter(env, print_str_pair);
	set_signal_handler();
	while (TRUE)
	{
		input = readline("dish-0.2$ ");
		if (!input)
			break ;
		tokenized_lst = tokenize(input);
		ft_lstiter(tokenized_lst, print_token);
		if (check_syntax(tokenized_lst->next))
		{
			expand(tokenized_lst, env);
			parse_tree = parse_lst(tokenized_lst->next);
		}
		add_history(input);
		ft_lstdelone(tokenized_lst, del_token);
		//ft_treeclear(&parse_tree, del_token);
		ft_lstclear(&tokenized_lst, del_token);
		free(input);
	}
	ft_lstclear(&env, del_str_pair);
	printf("exit\n");
	return (0);
}
