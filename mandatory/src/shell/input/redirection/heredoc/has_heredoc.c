/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:00:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 15:51:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/input.h"

t_bool	has_heredoc(t_list *lst)
{
	while (lst)
	{
		if (((t_token *)lst->content)->type == DLESS)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}
