/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:25:49 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/14 16:36:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/type.h"
#include <stdlib.h>

t_tree	*ft_treenew(void *content)
{
	t_tree	*ret;

	ret = (t_tree *)malloc(sizeof(t_tree));
	if (!ret)
		return (0);
	ret->content = content;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}
