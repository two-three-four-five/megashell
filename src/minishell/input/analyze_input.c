/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:38:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/16 21:42:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/parse.h"
#include "shell/type.h"

void	analyze_input(char *input, t_dict *env)
{
	t_list	*lst;
	t_tree	*parse_tree;

	lst = tokenize(input);
	//ft_lstiter(lst, print_token);
	if (check_syntax(lst->next))
	{
		expand(lst, env);
		redirect_heredoc(lst);
		parse_tree = parse_lst(lst->next);
		//print_tree(parse_tree);
		ft_treeclear(&parse_tree, del_token);
		ft_lstdelone(lst, del_token);
	}
	else
		ft_lstclear(&lst, del_token);
}
