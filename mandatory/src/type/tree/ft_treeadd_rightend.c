/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd_rightend.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:51:11 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 14:46:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/tree.h"

void	ft_treeadd_rightend(t_tree **tree, t_tree *node)
{
	t_tree	*right;

	right = *tree;
	if (!right)
	{
		*tree = node;
		return ;
	}
	while (right->right)
		right = right->right;
	right->right = node;
}
