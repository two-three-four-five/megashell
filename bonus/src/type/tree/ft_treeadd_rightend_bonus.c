/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd_rightend_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:51:11 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/tree_bonus.h"

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
