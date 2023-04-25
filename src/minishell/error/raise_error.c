/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:35:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/25 22:37:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/error.h"

void	raise_error(int errno)
{
	if (errno == PARSE_ERR_NOT_ENOUGH_QUOTE)
		ft_putstr_fd("parse error : not enough quote\n", 0);
}
