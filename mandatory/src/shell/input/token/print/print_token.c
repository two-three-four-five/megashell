/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:36:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/24 01:53:21 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "shell/input.h"

void	print_token(void *ptr)
{
	t_token	*token;

	token = (t_token *)ptr;
	if (!token)
		printf("    type | token\n");
	else
		printf("%8x | %s\n", token->type, token->token);
}
