/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:38:21 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/29 18:04:53 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
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
	if (lst->next && ((t_token *)lst->next->content)->type != NL)
		add_history(input);
	if (!check_syntax(lst->next, env))
		return (parse_input_failed(&lst));
	else
	{
		if (has_heredoc(lst->next) && !redirect_heredoc(lst->next, env))
			return (parse_input_failed(&lst));
		del_token_lstlast(lst);
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
