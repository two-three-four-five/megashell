/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:03:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 14:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/parse.h"

#include <stdio.h>

static t_bool	is_subshell(t_list *lst);
static t_bool	has_pipe(t_list *lst);
static t_bool	has_logic_operator(t_list *lst);
t_tree			*parse_lst(t_list *lst);

t_tree	*parse_lst(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	else if (is_subshell(lst))
		return (parse_subshell(lst));
	else if (has_logic_operator(lst))
		return (parse_logic(lst));
	else if (has_pipe(lst))
		return (parse_pipe(lst));
	else if (((t_token *)lst->content)->type == OPEN_PAREN)
		return (parse_subshell_with_redirect(lst));
	else
		return (parse_command(lst));
}

static t_bool	is_subshell(t_list *lst)
{
	int	subshell;

	if (((t_token *)lst->content)->type != OPEN_PAREN)
		return (FALSE);
	subshell = 0;
	while (lst)
	{
		if (((t_token *)lst->content)->type == OPEN_PAREN)
			subshell++;
		else if (((t_token *)lst->content)->type == CLOSE_PAREN)
			subshell--;
		if (subshell == 0 && lst->next == NULL)
			return (TRUE);
		else if (subshell == 0 && lst->next != NULL)
			return (FALSE);
		lst = lst->next;
	}
	return (FALSE);
}

static t_bool	has_pipe(t_list *lst)
{
	int	subshell;

	subshell = 0;
	while (lst)
	{
		if (((t_token *)lst->content)->type == OPEN_PAREN)
			subshell++;
		else if (((t_token *)lst->content)->type == CLOSE_PAREN)
			subshell--;
		if (subshell == 0 && ((t_token *)lst->content)->type == PIPE)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

static t_bool	has_logic_operator(t_list *lst)
{
	int	subshell;

	subshell = 0;
	while (lst)
	{
		if (((t_token *)lst->content)->type == OPEN_PAREN)
			subshell++;
		else if (((t_token *)lst->content)->type == CLOSE_PAREN)
			subshell--;
		if (subshell == 0 && ((t_token *)lst->content)->type & LOGIC)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}
