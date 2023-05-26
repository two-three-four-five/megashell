/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:23:52 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/26 20:12:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "type_bonus.h"

t_bool	is_directory(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (TRUE);
	}
	else
		return (FALSE);
}
