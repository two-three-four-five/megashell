/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:05:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/28 01:57:27 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "type_bonus.h"
#include "shell_bonus.h"

t_bool	check_syntax(t_list *lst, t_dict *env)
{
	(void)env;
	if (!check_undefined_token(lst) || \
		!check_matching_syntax(lst) || \
		!check_token_order(lst))
	{
		g_exit_status = 2;
		return (FALSE);
	}
	else
		return (TRUE);
}
