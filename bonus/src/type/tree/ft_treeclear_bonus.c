/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeclear_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:07:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "type/tree_bonus.h"

void	ft_treeclear(t_tree **tree, void (*del)(void *))
{
	t_tree	*curr;

	curr = *tree;
	if (!curr)
		return ;
	ft_treeclear(&curr->left, del);
	ft_treeclear(&curr->right, del);
	del(curr->content);
	free(curr);
	*tree = NULL;
}
