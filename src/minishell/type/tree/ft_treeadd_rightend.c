/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd_rightend.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:51:11 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 21:05:17 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"

void	ft_treeadd_rightend(t_tree **tree, t_tree *new)
{
	t_tree	*right;

	right = *tree;
	if (!right)
	{
		*tree = new;
		return ;
	}
	while (right->right)
		right = right->right;
	right->right = new;
}
