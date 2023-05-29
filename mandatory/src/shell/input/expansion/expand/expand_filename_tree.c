/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_filename_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:00:08 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/29 18:00:05 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/input.h"
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static t_bool	is_matching(char *s, char *pattern);
static t_bool	has_unquoted_wildcard(char *s);
static t_list	*get_matching_file_lst(char *pattern);
static void		change_filename_lst(t_list **file_lst, t_list **lst, int *prev);
void			expand_filename_tree(t_list *lst);

void	expand_filename_tree(t_list *lst)
{
	t_list	*file_lst;
	int		prev;

	lst = lst->next;
	prev = UNDEFINED;
	while (lst)
	{
		if (((t_token *)lst->content)->type == WORD && \
			has_unquoted_wildcard(((t_token *)lst->content)->token))
		{
			file_lst = get_matching_file_lst(((t_token *)lst->content)->token);
			if (file_lst)
				change_filename_lst(&file_lst, &lst, &prev);
			else
			{
				prev = ((t_token *)lst->content)->type;
				lst = lst->next;
			}
			continue ;
		}
		prev = ((t_token *)lst->content)->type;
		lst = lst->next;
	}
}

static void	change_filename_lst(t_list **file_lst, t_list **lst, int *prev)
{
	t_list	*temp;

	if (*prev & _REDIRECT && *prev != DLESS && ft_lstsize(*file_lst) != 1)
	{
		((t_token *)(*lst)->content)->type = AMBIGUOUS;
		ft_lstclear(file_lst, del_token);
		*prev = ((t_token *)(*lst)->content)->type;
		*lst = (*lst)->next;
	}
	else
	{
		((t_token *)(*lst)->content)->token[0] = '\0';
		ft_lstadd_back(file_lst, (*lst)->next);
		temp = (*lst)->next;
		(*lst)->next = *file_lst;
		*prev = ((t_token *)(*lst)->content)->type;
		*lst = temp;
	}
}

static t_bool	has_unquoted_wildcard(char *s)
{
	t_bool	quote;
	t_bool	dquote;

	quote = FALSE;
	dquote = FALSE;
	while (*s)
	{
		if (!dquote && *s == '\'')
			quote = !quote;
		else if (!quote && *s == '\"')
			dquote = !dquote;
		else if (!quote && !dquote && *s == '*')
			return (TRUE);
		s++;
	}
	return (FALSE);
}

static t_bool	is_matching(char *s, char *pattern)
{
	size_t	idx;
	size_t	repeat;

	idx = 0;
	while (s[idx] && pattern[idx] && \
			(pattern[idx] == '?' || pattern[idx] == s[idx]))
		idx++;
	if (idx == ft_strlen(pattern))
		return ((t_bool)(idx == ft_strlen(s)));
	if (pattern[idx] == '*')
	{
		repeat = 0;
		while (repeat <= ft_strlen(s) - idx)
		{
			if (is_matching(s + repeat, pattern + 1))
				return (TRUE);
			repeat++;
		}
	}
	return (FALSE);
}

static t_list	*get_matching_file_lst(char *pattern)
{
	char			*pwd;
	DIR				*dir;
	struct dirent	*file;
	t_list			*head;
	t_list			*node;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (NULL);
	dir = opendir(pwd);
	head = NULL;
	while (TRUE)
	{
		file = readdir(dir);
		if (!file)
			break ;
		if (file->d_name[0] != '.' && is_matching(file->d_name, pattern))
		{
			node = ft_lstnew(new_token(FILENAME, ft_strdup(file->d_name)));
			ft_lstadd_back(&head, node);
		}
	}
	closedir(dir);
	free(pwd);
	return (head);
}
