/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd_leftend copy.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:51:11 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 21:04:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"

void	ft_treeadd_leftend(t_tree **tree, t_tree *new)
{
	t_tree	*left;

	left = *tree;
	if (!left)
	{
		*tree = new;
		return ;
	}
	while (left->left)
		left = left->left;
	left->left = new;
}
