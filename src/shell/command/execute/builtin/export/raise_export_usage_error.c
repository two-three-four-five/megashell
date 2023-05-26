/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_export_usage_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:56:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 17:32:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "type.h"

int	raise_export_usage_error(t_tree *tree)
{
	while (tree)
	{
		if (((t_token *)tree->content)->token[0] == '-')
		{
			ft_putstr_fd("bash: export: ", 2);
			ft_putstr_fd(((t_token *)tree->content)->token, 2);
			ft_putendl_fd(" invalid option", 2);
			ft_putendl_fd("export: usage: export [name[=value] ...]", 2);
			return (2);
		}
		else
			break ;
		tree = tree->left;
	}
	return (2);
}
