/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_newline_order_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:52:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/input_bonus.h"

t_bool	check_newline_order(int prev, int curr)
{
	if ((curr == NL) && \
		(prev == PIPE || prev & _LOGIC \
			|| prev & _REDIRECT || prev == OPEN_PAREN))
		return (FALSE);
	else
		return (TRUE);
}
