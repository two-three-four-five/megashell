/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator_order.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:53:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 22:55:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/parse.h"

t_bool	check_operator_order(char prev, char curr)
{
	if ((curr == PIPE || curr == AND_IF || curr == OR_IF) && \
		(prev == PIPE || prev == NEWLINE || prev & LOGIC || \
			prev & REDIRECT || prev == OPEN_PAREN || prev == UNDEFINED))
		return (FALSE);
	else if ((curr & REDIRECT) && \
		(prev == PIPE || prev == NEWLINE || prev & LOGIC || prev & REDIRECT))
		return (FALSE);
	else if ((curr == OPEN_PAREN) && \
		(prev == WORD || prev == NEWLINE || \
			prev & REDIRECT || prev == CLOSE_PAREN))
		return (FALSE);
	else if ((curr == CLOSE_PAREN) && \
			(prev == PIPE || prev == NEWLINE || prev & LOGIC || \
				prev & REDIRECT || prev == OPEN_PAREN || prev == UNDEFINED))
		return (FALSE);
	else
		return (TRUE);
}
