/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:00:08 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/08 21:58:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//t_bool	is_matching(char *s, char *pattern);
t_bool	has_unquoted_wildcard(char *s);
t_list	*get_matching_file_lst(char *pattern);
void	expand_filename(t_list *lst);

void	expand_filename(t_list *lst)
{
	t_list	*filename_lst;
	t_list	*temp;

	lst = lst->next;
	while (lst)
	{
		if (((t_token *)lst->content)->type == WORD && \
			has_unquoted_wildcard(((t_token *)lst->content)->token))
		{
			filename_lst = get_matching_file_lst("*");
			if (filename_lst)
			{
				((t_token *)lst->content)->token[0] = 0;
				ft_lstadd_back(&filename_lst, lst->next);
				temp = lst->next;
				lst->next = filename_lst;
				lst = temp;
			}
			else
				lst = lst->next;
		}
		else
			lst = lst->next;
	}
}

t_bool	has_unquoted_wildcard(char *s)
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


// t_bool	is_matching(char *s, char *pattern)
// {

// }

t_list	*get_matching_file_lst(char *pattern)
{
	char			*pwd;
	DIR				*dir;
	struct dirent	*file;
	t_list			*head;
	t_list			*node;

	(void)pattern;
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
		if (file->d_name[0] != '.')
		{
			node = ft_lstnew(new_token(FILENAME, ft_strdup(file->d_name)));
			ft_lstadd_back(&head, node);
		}
	}
	closedir(dir);
	free(pwd);
	return (head);
}
