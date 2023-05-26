/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_heredoc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:00:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/input_bonus.h"

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
