/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:24:17 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type_bonus.h"

t_bool	is_executable(char *filename)
{
	if (access(filename, X_OK) == 0)
		return (TRUE);
	else
		return (FALSE);
}
