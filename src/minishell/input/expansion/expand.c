/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:51:08 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/08 22:01:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"
#include "shell/parse.h"

void	expand(t_list *lst, t_dict *env)
{
	expand_parameter(lst, env);
	expand_filename(lst);
	//delete_empty_word(lst);
	//split_word(lst);
	remove_quote(lst);
}
