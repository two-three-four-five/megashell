/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:26:39 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 21:28:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"
#include "shell/parse.h"
#include <stdio.h>

void	print_tree(t_tree *tree)
{
	if (!tree)
		return ;
	print_token(tree->content);
	print_tree(tree->left);
	print_tree(tree->right);
}
