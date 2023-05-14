/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:07:46 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 21:10:56 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"
#include <stdlib.h>

void	ft_treeclear(t_tree **tree, void (*del)(void *))
{
	t_tree	*curr;

	curr = *tree;
	if (!curr)
		return ;
	ft_treeclear(&curr->left, del);
	ft_treeclear(&curr->right, del);
	free(curr);
	*tree = NULL;
}
