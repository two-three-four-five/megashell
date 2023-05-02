/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/02 17:24:09 by gyoon            ###   ########.fr       */
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
	while (lst)
	{
		printf("%3d | type(%2d) | %s\n", i++, ((t_token *)lst->content)->type, \
										((t_token *)lst->content)->token);
		lst = lst->next;
	}
}

void	print_dict_lst(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("%3d | %-30s | %s\n", i++, ((t_dict *)lst->content)->key, \
										((t_dict *)lst->content)->value);
		lst = lst->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_list		*tokenized_lst;
	t_list		*envp_lst;

	(void)argc;
	(void)argv;
	envp_lst = get_envp_lst(envp);
	print_dict_lst(envp_lst);
	set_signal_handler();
	while (TRUE)
	{
		input = readline("dish-0.2$ ");
		if (!input)
			break ;
		tokenized_lst = tokenize(input);
		if (check_syntax(tokenized_lst))
			print_token_lst(tokenized_lst);
		add_history(input);
		ft_lstclear(&tokenized_lst, del_token);
		free(input);
	}
	printf("exit\n");
	return (0);
}
