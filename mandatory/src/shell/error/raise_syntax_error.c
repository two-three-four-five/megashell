/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:35:07 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/25 23:41:53 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/error.h"

void	raise_syntax_error(int errno, char *token, char c1, char c2)
{
	ft_putstr_fd(MSG_DISH, 2);
	if (errno == UNDEFINED_TOKEN)
	{
		ft_putstr_fd("syntax error undefined operator `", 2);
		ft_putstr_fd(token, 2);
		ft_putendl_fd("\'", 2);
	}
	else if (errno == MISSING_TOKEN)
	{
		ft_putchar_fd(c1, 2);
		ft_putstr_fd(": missing `", 2);
		ft_putchar_fd(c2, 2);
		ft_putendl_fd("\'", 2);
	}
	else if (errno == UNEXPECTED_TOKEN)
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(token, 2);
		ft_putendl_fd("\'", 2);
	}
}
