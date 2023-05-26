/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin_cmd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:04:31 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_bonus.h"

t_bool	is_builtin_cmd(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "cd"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "pwd"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "export"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "unset"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "env"))
		return (TRUE);
	else if (!ft_strcmp(cmd, "exit"))
		return (TRUE);
	else
		return (FALSE);
}
