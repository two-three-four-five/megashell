/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:11:12 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/18 14:27:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*split_path(char *path)
{
	t_list	*head;
	t_list	*node;
	int		i;
	int		len;

	head = NULL;
	i = 0;
	while (path[i])
	{
		len = 0;
		while (path[i + len] != ':' && path[i + len] != '\0')
			len++;
		node = ft_lstnew(ft_substr(path, i, len));
		if (!node || !node->content)
			exit(1);
		ft_lstadd_back(&head, node);
		while (path[i] != ':' && path[i] != '\0')
			i++;
		if (path[i] == ':')
			i++;
	}
	return (head);
}
