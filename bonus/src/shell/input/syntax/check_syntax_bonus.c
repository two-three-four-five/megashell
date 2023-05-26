/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:05:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type_bonus.h"
#include "shell/input_bonus.h"
#include <stdio.h>

t_bool	check_syntax(t_list *lst, t_dict *env)
{
	(void)env;
	if (!check_undefined_token(lst) || \
		!check_matching_syntax(lst) || \
		!check_token_order(lst))
		return (FALSE);
	else
		return (TRUE);
}
