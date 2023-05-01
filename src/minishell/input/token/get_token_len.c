/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:33:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/01 20:04:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/parse.h"

int	get_token_len(char *s)
{
	char	type;

	type = get_token_type(s);
	if (type == AND_IF || type == OR_IF || \
		type == DLESS || type == DGREAT)
		return (2);
	else if (type == WORD)
		return (0);
	else
		return (1);
}
