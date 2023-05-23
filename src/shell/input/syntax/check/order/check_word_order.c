/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word_order.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:52:59 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/24 01:51:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/input.h"

t_bool	check_word_order(int prev, int curr)
{
	if ((curr == WORD) && \
		(prev == NL || prev == CLOSE_PAREN))
		return (FALSE);
	else
		return (TRUE);
}
