/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:13:12 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/input_bonus.h"
#include "type_bonus.h"

char	**get_argv(t_tree *tree)
{
	char	**argv;
	int		idx;

	argv = ft_calloc(ft_treeleftsize(tree) + 1, sizeof(char *));
	idx = 0;
	while (tree)
	{
		argv[idx++] = ft_strdup(((t_token *)tree->content)->token);
		tree = tree->left;
	}
	return (argv);
}
