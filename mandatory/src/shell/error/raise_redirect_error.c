/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_redirect_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:50:55 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/25 23:41:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/error.h"

void	raise_redirect_error(char *token)
{
	ft_putstr_fd(MSG_DISH, 2);
	ft_putstr_fd(token, 2);
	ft_putendl_fd(MSG_AMBIGUOUS_REDIRECT, 2);
}
