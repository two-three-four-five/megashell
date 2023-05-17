/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:49:53 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 19:52:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"

char	*remove_quote_token(char *token)
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
