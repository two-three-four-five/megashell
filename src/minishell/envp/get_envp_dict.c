/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:20:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/02 20:34:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"

static void	*clear_dict(t_dict **dict, void (*del)(void *));

t_dict	*get_envp_dict(char **envp)
{
	t_dict	*lst;
	t_dict	*node;

	lst = NULL;
	while (*envp)
	{
		node = ft_lstnew(\
					new_str_pair(\
						ft_substr(*envp, 0, ft_strchr(*envp, '=') - *envp), \
						ft_strdup(ft_strchr(*envp, '=') + 1)));
		if (!node)
			return (clear_dict(&lst, del_str_pair));
		else if (!node->content)
		{
			free(node);
			return (clear_dict(&lst, del_str_pair));
		}
		ft_lstadd_back(&lst, node);
		envp++;
	}
	return (lst);
}

static void	*clear_dict(t_dict **dict, void (*del)(void *))
{
	ft_lstclear(dict, del);
	return (NULL);
}
