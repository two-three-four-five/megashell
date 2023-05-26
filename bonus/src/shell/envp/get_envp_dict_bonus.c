/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_dict_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:20:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type_bonus.h"

static void	*clear_dict(t_dict **dict, void (*del)(void *));
static void	increment_shlvl(t_dict *dict);
t_dict		*get_envp_dict(char **envp);

t_dict	*get_envp_dict(char **envp)
{
	t_dict	*lst;
	t_dict	*node;

	lst = ft_lstnew(NULL);
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
	increment_shlvl(lst);
	return (lst);
}

static void	*clear_dict(t_dict **dict, void (*del)(void *))
{
	ft_lstclear(dict, del);
	return (NULL);
}

static void	increment_shlvl(t_dict *dict)
{
	int			shlvl;
	char		*value;
	t_str_pair	*str_pair;

	if (get_dict_value(dict->next, "SHLVL"))
	{
		shlvl = ft_atoi(get_dict_value(dict->next, "SHLVL"));
		value = ft_itoa(shlvl + 1);
		reassign_dict_value(dict->next, "SHLVL", value);
	}
	else
	{
		str_pair = new_str_pair(ft_strdup("SHLVL"), ft_strdup("1"));
		ft_lstadd_back(&dict, ft_lstnew(str_pair));
	}
}
