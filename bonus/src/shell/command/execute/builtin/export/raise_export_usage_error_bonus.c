/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_export_usage_error_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:56:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell_bonus.h"
#include "type_bonus.h"

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
