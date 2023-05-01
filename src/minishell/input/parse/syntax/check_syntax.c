/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:05:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/01 19:08:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdio.h>

t_bool	check_syntax(t_list *lst)
{
	if (!check_matching_syntax(lst) || !check_operator_syntax(lst))
		return (FALSE);
	else
		return (TRUE);
}
