/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 00:11:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/07 00:47:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdlib.h>

static int	count_quote(char *token);
static char	*remove_quote_token(char *token);
void		remove_quote(t_list *lst);

void	remove_quote(t_list *lst)
{
	char	*new_token;

	while (lst)
	{
		if (((t_token *)lst->content)->type == WORD)
		{
			new_token = remove_quote_token(\
				((t_token *)lst->content)->token);
			if (!new_token)
				return ;
			free(((t_token *)lst->content)->token);
			((t_token *)lst->content)->token = new_token;
		}
		lst = lst->next;
	}
}

static char	*remove_quote_token(char *token)
{
	t_bool	quote;
	t_bool	dquote;
	char	*new_token;
	int		idx;

	quote = FALSE;
	dquote = FALSE;
	new_token = (char *)ft_calloc(\
					ft_strlen(token) - count_quote(token) + 1, sizeof(char));
	if (!new_token)
		return (NULL);
	idx = 0;
	while (*token)
	{
		if (!dquote && *token == '\'')
			quote = !quote;
		else if (!quote && *token == '\"')
			dquote = !dquote;
		else
			new_token[idx++] = *token;
		token++;
	}
	return (new_token);
}

static int	count_quote(char *token)
{
	t_bool	quote;
	t_bool	dquote;
	int		quote_cnt;

	quote = FALSE;
	dquote = FALSE;
	quote_cnt = 0;
	while (*token)
	{
		if (!dquote && *token == '\'')
		{
			quote = !quote;
			quote_cnt++;
		}
		else if (!quote && *token == '\"')
		{
			dquote = !dquote;
			quote_cnt++;
		}
		token++;
	}
	return (quote_cnt);
}
