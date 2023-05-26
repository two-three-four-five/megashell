/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_quote_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:51:47 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type_bonus.h"

int	count_quote(char *token)
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
