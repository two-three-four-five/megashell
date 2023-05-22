/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 00:13:12 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 14:53:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/parse.h"
#include "type.h"

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
