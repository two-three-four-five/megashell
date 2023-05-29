/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:27:13 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/29 17:59:53 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/input.h"

static int		count_ifs(char *token);
static t_list	*split_token(char *token);
static char		*split_initial_word(char *token);
void			split_word_tree(t_list *lst);

void	split_word_tree(t_list *lst)
{
	t_list	*splitted_lst;
	t_list	*temp;

	lst = lst->next;
	while (lst)
	{
		if (((t_token *)lst->content)->type == WORD && \
			count_ifs(((t_token *)lst->content)->token))
		{
			splitted_lst = split_token(((t_token *)lst->content)->token);
			ft_lstadd_back(&splitted_lst, lst->next);
			temp = lst->next;
			lst->next = splitted_lst;
			((t_token *)lst->content)->token[0] = '\0';
			lst = temp;
		}
		else
			lst = lst->next;
	}
}

static int	count_ifs(char *token)
{
	t_bool	quote;
	t_bool	dquote;
	int		ifs_cnt;

	quote = FALSE;
	dquote = FALSE;
	ifs_cnt = 0;
	while (*token)
	{
		if (!dquote && *token == '\'')
			quote = !quote;
		else if (!quote && *token == '\"')
			dquote = !dquote;
		else if (!quote && !dquote && isdelimeter(*token))
			ifs_cnt++;
		token++;
	}
	return (ifs_cnt);
}

static t_list	*split_token(char *token)
{
	t_list	*head;
	t_list	*node;
	int		i;
	int		ifs;

	head = NULL;
	i = 0;
	ifs = count_ifs(token);
	while (i < ifs + 1)
	{
		node = ft_lstnew(new_token(WORD, split_initial_word(token)));
		if (!node || !node->content)
		{
			ft_lstclear(&head, del_token);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		token = token + ft_strlen(((t_token *)node->content)->token);
		while (isdelimeter(*token) || *token == '\0')
			token++;
		i++;
	}
	return (head);
}

static char	*split_initial_word(char *token)
{
	t_bool	quote;
	t_bool	dquote;
	int		len;
	char	*ret;

	quote = FALSE;
	dquote = FALSE;
	len = 0;
	while (token[len])
	{
		if (!dquote && token[len] == '\'')
			quote = !quote;
		else if (!quote && token[len] == '\"')
			dquote = !dquote;
		else if (!quote && !dquote && isdelimeter(token[len]))
			break ;
		len++;
	}
	ret = ft_substr(token, 0, len);
	return (ret);
}
