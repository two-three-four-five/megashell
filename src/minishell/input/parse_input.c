/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:38:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 21:08:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/parse.h"
#include "shell/type.h"

static t_tree	*parse_input_failed(t_list **lst);
t_tree			*parse_input(char *input, t_dict *env);

#include <stdio.h>

t_tree	*parse_input(char *input, t_dict *env)
{
	t_list	*lst;
	t_tree	*parse_tree;

	lst = tokenize(input);
	if (!lst)
		return (NULL);
	ft_lstiter(lst, print_token);
	if (!check_syntax(lst->next))
		return (parse_input_failed(&lst));
	else
	{
		if (has_heredoc(lst->next) && !redirect_heredoc(lst->next, env))
			return (parse_input_failed(&lst));
		expand_lst(lst, env);
		parse_tree = parse_lst(lst->next);
		printf("%10s", "head |");
		print_tree(parse_tree);
		ft_lstdelone(lst, del_token);
		return (parse_tree);
	}
}

static t_tree	*parse_input_failed(t_list **lst)
{
	ft_lstclear(lst, del_token);
	return (NULL);
}
