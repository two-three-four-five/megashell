/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeleftsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:20:30 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/22 14:46:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/tree.h"

int	ft_treeleftsize(t_tree *tree)
{
	int	size;

	size = 0;
	while (tree)
	{
		++size;
		tree = tree->left;
	}
	return (size);
}
