/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:04:36 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/22 15:51:55 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell/input.h"

t_token	*new_token(char type, char *str)
{
	t_token	*token;

	if (!str)
		return (NULL);
	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		if (str)
			free(str);
		return (NULL);
	}
	token->type = type;
	token->token = str;
	return (token);
}
