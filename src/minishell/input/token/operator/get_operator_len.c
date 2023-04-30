/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operator_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:32:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/29 15:57:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_control_operator_len(char *s);
static int	get_redirection_operator_len(char *s);
int			get_operator_len(char *s);

int	get_operator_len(char *s)
{
	if (get_redirection_operator_len(s))
		return (get_redirection_operator_len(s));
	else if (get_control_operator_len(s))
		return (get_control_operator_len(s));
	else
		return (0);
}

static int	get_control_operator_len(char *s)
{
	if (!ft_strncmp("||", s, 2) || !ft_strncmp("&&", s, 2))
		return (2);
	else if (!ft_strncmp("&", s, 1) || !ft_strncmp(";", s, 1) || \
			!ft_strncmp("|", s, 1) || !ft_strncmp("(", s, 1) || \
			!ft_strncmp(")", s, 1))
		return (1);
	else
		return (0);
}

static int	get_redirection_operator_len(char *s)
{
	if (!ft_strncmp(">>", s, 2) || !ft_strncmp("<<", s, 2) || \
			!ft_strncmp("<>", s, 2))
		return (2);
	else if (!ft_strncmp("<", s, 1) || !ft_strncmp(">", s, 1))
		return (1);
	else
		return (0);
}

// static int	get_control_operator_len(char *s)
// {
// 	if (!ft_strncmp(";;&", s, 3))
// 		return (3);
// 	else if (!ft_strncmp("||", s, 2) || !ft_strncmp(";;", s, 2) || \
// 			!ft_strncmp("&&", s, 2) || !ft_strncmp(";&", s, 2) || \
// 			!ft_strncmp("|&", s, 2))
// 		return (2);
// 	else if (!ft_strncmp("&", s, 1) || !ft_strncmp(";", s, 1) || \
// 			!ft_strncmp("|", s, 1) || !ft_strncmp("(", s, 1) || \
// 			!ft_strncmp(")", s, 1))
// 		return (1);
// 	else
// 		return (0);
// }

// static int	get_redirection_operator_len(char *s)
// {
// 	if (!ft_strncmp("&>>", s, 3) || !ft_strncmp("<<-", s, 3) || \
// 		!ft_strncmp("<<<", s, 3))
// 		return (3);
// 	else if (!ft_strncmp(">|", s, 2) || !ft_strncmp(">>", s, 2) || \
// 			!ft_strncmp("&>", s, 2) || !ft_strncmp(">&", s, 2) || \
// 			!ft_strncmp("<<", s, 2) || !ft_strncmp("<&", s, 2) || \
// 			!ft_strncmp("<>", s, 2))
// 		return (2);
// 	else if (!ft_strncmp("<", s, 1) || !ft_strncmp(">", s, 1))
// 		return (1);
// 	else
// 		return (0);
// }
