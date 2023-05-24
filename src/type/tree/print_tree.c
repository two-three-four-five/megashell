/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:26:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/24 21:45:27 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "shell/input.h"
#include <stdio.h>

// void	_print_tree(t_tree *tree)
// {
// 	if (!tree)
// 		return ;
// 	printf("%10s", "curr |");
// 	print_token(tree->content);
// 	if (tree->left)
// 	{
// 		printf("%10s", "left |");
// 		print_tree(tree->left);
// 	}
// 	else
// 		printf("%10s\n", "no left |");
// 	if (tree->right)
// 	{
// 		printf("%10s", "right |");
// 		print_tree(tree->right);
// 	}
// 	else
// 		printf("%10s\n", "no right |");
// }

void	print_tree(t_tree *tree, char *prefix, int is_left)
{
	t_token	*token;

	if (tree == NULL)
		return ;
	token = tree->content;
	print_tree(tree->right, ft_strjoin(prefix, (is_left ? "    " : "│   ")), 0);
	printf("%s", prefix);
	printf("%s", is_left ? "└── " : "┌── ");
	printf("\"%s\"\n", token->token);
	print_tree(tree->left, ft_strjoin(prefix, (is_left ? "    " : "│   ")), 1);
}