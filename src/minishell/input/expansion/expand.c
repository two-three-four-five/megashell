/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:51:08 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/07 00:12:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"
#include "shell/parse.h"

void	expand(t_list **lst, t_dict *env)
{
	expand_parameter(*lst, env);
	remove_quote(*lst);
	expand_filename(*lst);
}
