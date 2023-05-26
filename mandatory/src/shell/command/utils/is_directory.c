/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:23:52 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/05/23 09:32:56 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "type.h"

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
