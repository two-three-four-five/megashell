/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/26 20:27:56 by gyoon            ###   ########.fr       */
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
#include <signal.h>

typedef struct sigaction	t_sigaction;

void	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("%d : %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

int	main(void)
{
	char		*input;
	t_list		*tokenized_lst;

	set_signal_handler();
	while (TRUE)
	{
		input = readline("dish-0.1$ ");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		printf("line : %s\n", input);
		tokenized_lst = tokenize(input);
		ft_lstprint(tokenized_lst);
		add_history(input);
		ft_lstclear(&tokenized_lst, free);
		free(input);
	}
	return (0);
}
