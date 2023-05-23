/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_executable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:24:17 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 09:34:31 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type.h"

t_bool	is_executable(char *filename)
{
	if (access(filename, X_OK) == 0)
		return (TRUE);
	else
		return (FALSE);
}
