/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:32:34 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/24 01:46:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/input.h"

static int	get_control_operator_type(char *s);
static int	get_redirection_operator_type(char *s);
int			get_token_type(char *s);

int	get_token_type(char *s)
{
	int	ctrl_operator;
	int	redirect_operator;

	ctrl_operator = get_control_operator_type(s);
	redirect_operator = get_redirection_operator_type(s);
	if (ctrl_operator != WORD)
		return (ctrl_operator);
	else if (redirect_operator)
		return (redirect_operator);
	else
		return (WORD);
}

static int	get_control_operator_type(char *s)
{
	if (!ft_strncmp(s, "&&", 2))
		return (AND_IF);
	else if (!ft_strncmp(s, "||", 2))
		return (OR_IF);
	else if (!ft_strncmp(s, "|", 1))
		return (PIPE);
	else if (!ft_strncmp(s, "(", 1))
		return (OPEN_PAREN);
	else if (!ft_strncmp(s, ")", 1))
		return (CLOSE_PAREN);
	else if (!ft_strncmp(s, "&", 1))
		return (UNDEFINED);
	else if (!ft_strncmp(s, ";", 1))
		return (UNDEFINED);
	else
		return (WORD);
}

static int	get_redirection_operator_type(char *s)
{
	if (!ft_strncmp(s, "<<", 2))
		return (DLESS);
	else if (!ft_strncmp(s, ">>", 2))
		return (DGREAT);
	else if (!ft_strncmp(s, "<", 1))
		return (LESS);
	else if (!ft_strncmp(s, ">", 1))
		return (GREAT);
	else
		return (WORD);
}
