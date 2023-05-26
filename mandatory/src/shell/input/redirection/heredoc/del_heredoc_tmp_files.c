/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_heredoc_tmp_files.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:27:52 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/23 21:32:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"
#include "type.h"

void	del_heredoc_tmp_files(t_tree *tree)
{
	if (!tree)
		return ;
	if (((t_token *)tree->content)->type == DLESS)
		unlink(((t_token *)tree->left->content)->token);
	del_heredoc_tmp_files(tree->left);
	del_heredoc_tmp_files(tree->right);
}
