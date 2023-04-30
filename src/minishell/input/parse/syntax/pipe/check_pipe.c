/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:19:22 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/30 16:46:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
// #include <shell/type.h>
// #include <shell/parse.h>
// #include <stdio.h>

// static

// t_bool	check_pipe(t_list *lst)
// {
// 	char	*last_token;

// 	last_token = NULL;
// 	while (lst)
// 	{
// 		if (ft_strncmp(lst->content, "|", 1) || \
// 			!ft_strncmp(lst->content, "||", 2))
// 		{
// 			if (!last_token && !lst->next)
// 				printf("dish: syntax error near unexpected token `%s\'\n", token);
// 		}

// 		last_token = (char *)lst->content;
// 		lst = lst->next;
// 	}
// 	return (TRUE);
// }
