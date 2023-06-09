/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:26:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 15:51:19 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "shell/input.h"
#include <stdio.h>

void	print_tree(t_tree *tree)
{
	if (!tree)
		return ;
	printf("%10s", "curr |");
	print_token(tree->content);
	if (tree->left)
	{
		printf("%10s", "left |");
		print_tree(tree->left);
	}
	else
		printf("%10s\n", "no left |");
	if (tree->right)
	{
		printf("%10s", "right |");
		print_tree(tree->right);
	}
	else
		printf("%10s\n", "no right |");
}
