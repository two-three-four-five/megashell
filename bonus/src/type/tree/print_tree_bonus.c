/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:26:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"
#include "shell/input_bonus.h"
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
