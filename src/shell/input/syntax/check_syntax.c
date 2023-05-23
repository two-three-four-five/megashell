/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:05:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/23 23:07:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type.h"
#include "shell/input.h"
#include <stdio.h>

t_bool	check_syntax(t_list *lst, t_dict *env)
{
	if (!check_undefined_token(lst) || \
		!check_matching_syntax(lst) || \
		!check_token_order(lst))
		return (FALSE);
	else if (!check_redirect_syntax(lst, env))
		return (FALSE);
	else
		return (TRUE);
}
