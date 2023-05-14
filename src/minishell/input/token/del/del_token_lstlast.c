/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token_lstlast.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:08:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 16:08:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/parse.h"

void	del_token_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next->next)
		{
			ft_lstdelone(lst->next, del_token);
			lst->next = NULL;
		}
		lst = lst->next;
	}
}
