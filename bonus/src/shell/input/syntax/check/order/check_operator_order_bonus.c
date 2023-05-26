/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator_order_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:53:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/input_bonus.h"

t_bool	check_operator_order(int prev, int curr)
{
	if ((curr == PIPE || curr == AND_IF || curr == OR_IF) && \
		(prev == PIPE || prev == NL || prev & _LOGIC || \
			prev & _REDIRECT || prev == OPEN_PAREN || prev == UNDEFINED))
		return (FALSE);
	else if ((curr & _REDIRECT) && \
		(prev == NL || prev & _LOGIC || prev & _REDIRECT))
		return (FALSE);
	else if ((curr == OPEN_PAREN) && \
		(prev == WORD || prev == NL || \
			prev & _REDIRECT || prev == CLOSE_PAREN))
		return (FALSE);
	else if ((curr == CLOSE_PAREN) && \
			(prev == PIPE || prev == NL || prev & _LOGIC || \
				prev & _REDIRECT || prev == OPEN_PAREN || prev == UNDEFINED))
		return (FALSE);
	else
		return (TRUE);
}
