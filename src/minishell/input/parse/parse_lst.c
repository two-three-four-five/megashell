/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:03:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 17:59:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"

#include <stdio.h>

t_bool	is_subshell(t_list *lst)
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

t_bool	has_pipe(t_list *lst)
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

t_bool	has_logic_operator(t_list *lst)
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

t_bool	has_redirect(t_list *lst)
{
	int	subshell;

	subshell = 0;
	while (lst)
	{
		if (((t_token *)lst->content)->type == OPEN_PAREN)
			subshell++;
		else if (((t_token *)lst->content)->type == CLOSE_PAREN)
			subshell--;
		if (subshell == 0 && ((t_token *)lst->content)->type & REDIRECT)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

t_tree	*parse_lst(t_list *lst)
{
	t_tree	*head;
	t_list	*left;
	t_list	*right;

	if (lst == NULL)
		return (NULL);
	head = NULL;
	left = NULL;
	right = NULL;
	if (is_subshell(lst))
	{
		printf("** subshell **\n");
		del_token_lstlast(lst);
		head = ft_treenew(new_token(SUBSHELL, ft_strdup("()")));
		head->left = parse_lst(lst->next);
		head->right = NULL;
		ft_lstdelone(lst, del_token);
	}
	else if (has_pipe(lst))
	{
		printf("** pipe **\n");
		head = ft_treenew(new_token(PIPE, ft_strdup("|")));
		head->left = ft_treenew(new_token(SUBSHELL, ft_strdup("()")));
		head->right = ft_treenew(new_token(SUBSHELL, ft_strdup("()")));


		int		subshell = 0;
		t_list	*prev;
		t_list	*curr;

		prev = NULL;
		curr = lst;
		while (curr)
		{
			if (((t_token *)curr->content)->type == OPEN_PAREN)
				subshell++;
			else if (((t_token *)curr->content)->type == CLOSE_PAREN)
				subshell--;
			if (subshell == 0 && ((t_token *)curr->content)->type == PIPE)
			{
				right = curr->next;
				curr->next = NULL;
				left = lst;
				break ;
			}
			prev = curr;
			curr = curr->next;
		}
		del_token_lstlast(left);
		printf("%-10s", "left :");
		ft_lstiter(left, print_token);
		printf("%-10s", "right :");
		ft_lstiter(right, print_token);
		head->left->left = parse_lst(left);
		head->right->left = parse_lst(right);
	}
	else if (has_logic_operator(lst))
	{
		printf("** logic **\n");
		head = ft_treenew(new_token(REDIRECT, ft_strdup("&&||")));
		head->left = ft_treenew(new_token(SUBSHELL, ft_strdup("()")));
		head->right = ft_treenew(new_token(SUBSHELL, ft_strdup("()")));

		int		subshell = 0;
		t_list	*prev;
		t_list	*curr;

		prev = NULL;
		curr = lst;
		while (curr)
		{
			if (((t_token *)curr->content)->type == OPEN_PAREN)
				subshell++;
			else if (((t_token *)curr->content)->type == CLOSE_PAREN)
				subshell--;
			if (subshell == 0 && ((t_token *)curr->content)->type & LOGIC)
			{
				right = curr->next;
				curr->next = NULL;
				left = lst;
				break ;
			}
			prev = curr;
			curr = curr->next;
		}
		del_token_lstlast(left);
		printf("%-10s", "left :");
		ft_lstiter(left, print_token);
		printf("%-10s", "right :");
		ft_lstiter(right, print_token);
		head->left->left = parse_lst(left);
		head->right->left = parse_lst(right);
	}
	else
	{
		printf("** command **\n");
		if (has_redirect(lst))
		{
			printf("** redirect **\n");
		}
	}
	return (head);
}
