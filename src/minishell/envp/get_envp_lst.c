/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:20:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/02 17:10:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"

static void	*clear_lst(t_list **lst, void (*del)(void *));

t_list	*get_envp_lst(char **envp)
{
	t_list	*lst;
	t_list	*node;

	lst = NULL;
	while (*envp)
	{
		node = ft_lstnew(\
					new_dict(\
						ft_substr(*envp, 0, ft_strchr(*envp, '=') - *envp), \
						ft_strdup(ft_strchr(*envp, '=') + 1)));
		if (!node)
			return (clear_lst(&lst, del_dict));
		else if (!node->content)
		{
			free(node);
			return (clear_lst(&lst, del_dict));
		}
		ft_lstadd_back(&lst, node);
		envp++;
	}
	return (lst);
}

static void	*clear_lst(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}
