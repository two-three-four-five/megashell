/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:01:22 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/26 00:35:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"

char	*get_next_token(char *s)
{
	char	*token;
	char	quote;
	size_t	len;

	len = 0;
	quote = 0;
	while (s[len])
	{
		if (!len && get_operator_len(s))
		{
			len = get_operator_len(s);
			break ;
		}
		else if (quote && s[len] == quote)
			quote = 0;
		else if (!quote && isquote(s[len]))
			quote = s[len];
		else if (!quote && ismeta(s[len]))
			break ;
		len++;
	}
	if (!len)
		return (NULL);
	token = ft_substr(s, 0, len);
	return (token);
}
