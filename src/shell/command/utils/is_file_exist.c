/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:26:16 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 09:34:39 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type.h"

t_bool	is_file_exist(char *filename)
{
	if (access(filename, F_OK) == 0)
		return (TRUE);
	else
		return (FALSE);
}
