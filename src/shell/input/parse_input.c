/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:38:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 15:51:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/input.h"
#include "type.h"

static t_tree	*parse_input_failed(t_list **lst);
t_tree			*parse_input(char *input, t_dict *env);

t_tree	*parse_input(char *input, t_dict *env)
{
	t_list	*lst;
	t_tree	*ptree;

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
		ptree = parse_lst(lst->next);
		ft_lstdelone(lst, del_token);
		return (ptree);
	}
}

static t_tree	*parse_input_failed(t_list **lst)
{
	ft_lstclear(lst, del_token);
	return (NULL);
}
