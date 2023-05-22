/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:36:57 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 21:16:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell/parse.h"
#include <stdio.h>

void	print_token(void *ptr)
{
	t_token	*token;

	token = (t_token *)ptr;
	if (!token)
		printf("    type | token\n");
	else
		printf("%8d | %s\n", token->type, token->token);
}
