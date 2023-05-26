/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export_nop_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:31:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "shell_bonus.h"
#include "type_bonus.h"

static void	print_env_in_lexicographical_order(t_dict *dict, t_dict *key_dict);
static void	print_env_export(char *key, char *value);
int			execute_export_nop(t_tree *tree, t_dict *env);

int	execute_export_nop(t_tree *tree, t_dict *env)
{
	t_dict	*key_dict;

	(void)tree;
	key_dict = ft_lstnew(NULL);
	key_dict->next = ft_lstmap(env->next, dup_str_pair_s1, del_str_pair);
	print_env_in_lexicographical_order(env, key_dict);
	ft_lstclear(&key_dict, free);
	return (0);
}

static void	print_env_in_lexicographical_order(t_dict *env, t_dict *key_dict)
{
	t_dict	*prev;
	t_dict	*curr;
	t_dict	*min_prev;
	t_dict	*min;

	while (key_dict->next)
	{
		prev = key_dict;
		curr = key_dict->next;
		min_prev = key_dict;
		min = key_dict->next;
		while (curr)
		{
			if (ft_strcmp(min->content, curr->content) > 0)
			{
				min_prev = prev;
				min = curr;
			}
			prev = curr;
			curr = curr->next;
		}
		min_prev->next = min->next;
		print_env_export(min->content, get_dict_value(env->next, min->content));
		ft_lstdelone(min, free);
	}
}

static void	print_env_export(char *key, char *value)
{
	if (value)
		printf("declare -x %s=\"%s\"\n", key, value);
	else
		printf("declare -x %s\n", key);
}
