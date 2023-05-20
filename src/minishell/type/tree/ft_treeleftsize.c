/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeleftsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:20:30 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/20 14:21:32 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"

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
