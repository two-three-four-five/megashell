/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:00:08 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/07 00:49:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	expand_filename(t_list *lst)
{
	char			*pwd;
	DIR				*dir;
	struct dirent	*file;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return ;
	dir = opendir(pwd);
	while (TRUE)
	{
		file = readdir(dir);
		if (!file)
			break ;
		if (file->d_name[0] != '.')
			printf("%20s | %d\n", file->d_name, file->d_type);
	}
	closedir(dir);
	free(pwd);
	(void)lst;
}
