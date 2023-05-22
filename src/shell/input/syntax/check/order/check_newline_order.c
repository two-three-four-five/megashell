/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_newline_order.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:52:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 17:25:13 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/input.h"

t_bool	check_newline_order(char prev, char curr)
{
	if ((curr == NL) && \
		(prev == PIPE || prev & LOGIC || prev & REDIRECT || prev == OPEN_PAREN))
		return (FALSE);
	else
		return (TRUE);
}
