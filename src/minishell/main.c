/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/02 16:16:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/signal.h"
#include "shell/parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("%3d | type(%2d) | %s\n", i, ((t_token *)lst->content)->type, \
										((t_token *)lst->content)->token);
		lst = lst->next;
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_list		*tokenized_lst;

	(void)argv;
	(void)argv;
	set_signal_handler();
	while (TRUE)
	{
		input = readline("dish-0.2$ ");
		if (!input)
			break ;
		tokenized_lst = tokenize(input);
		if (check_syntax(tokenized_lst))
			ft_lstprint(tokenized_lst);
		add_history(input);
		ft_lstclear(&tokenized_lst, del_token);
		free(input);
	}
	printf("exit\n");
	return (0);
}
