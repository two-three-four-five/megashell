/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_exist_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:26:16 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type_bonus.h"

t_bool	is_file_exist(char *filename)
{
	if (access(filename, F_OK) == 0)
		return (TRUE);
	else
		return (FALSE);
}
