/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/08 21:56:09 by gyoon            ###   ########.fr       */
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

void	print_token_lst(t_list *lst)
{
	int	i;

	i = 0;
	printf("---------------------------------------------------------\n");
	while (lst)
	{
		printf("%3d | type(%2d) | %s\n", i++, ((t_token *)lst->content)->type, \
										((t_token *)lst->content)->token);
		lst = lst->next;
	}
	printf("---------------------------------------------------------\n");
}

void	print_dict(t_dict *lst)
{
	int	i;

	i = 0;
	printf("---------------------------------------------------------\n");
	while (lst)
	{
		printf("%3d | %-30s | %s\n", i++, ((t_str_pair *)lst->content)->s1, \
										((t_str_pair *)lst->content)->s2);
		lst = lst->next;
	}
	printf("---------------------------------------------------------\n");
}

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

	if (!check_arg(argc, argv))
	{
		printf("usage : ./minishell\n");
		return (1);
	}
	env = get_envp_dict(envp);
	print_dict(env);
	set_signal_handler();
	while (TRUE)
	{
		input = readline("dish-0.2$ ");
		if (!input)
			break ;
		tokenized_lst = tokenize(input);
		check_syntax(tokenized_lst->next);
		expand(tokenized_lst, env);
		print_token_lst(tokenized_lst->next);
		add_history(input);
		ft_lstclear(&tokenized_lst, del_token);
		free(input);
	}
	ft_lstclear(&env, del_str_pair);
	printf("exit\n");
	return (0);
}
