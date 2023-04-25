/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:12:33 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/25 17:06:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

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
	char	*input;

	while (TRUE)
	{
		input = readline("dish-0.1$");
		printf("line : %s\n", input);
		ft_lstprint(tokenize(input));
		add_history(input);
		free(input);
	}
	return (0);
}
