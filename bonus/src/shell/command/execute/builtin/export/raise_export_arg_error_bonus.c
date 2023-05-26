/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_export_arg_error_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:57:53 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 20:12:49 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell_bonus.h"
#include "type_bonus.h"

static void	put_export_arg_error_fd(char *str);
int			raise_export_arg_error(t_tree *tree);

int	raise_export_arg_error(t_tree *tree)
{
	char	*arg;

	arg = ((t_token *)tree->content)->token;
	if (!ft_isalpha(*arg) && *arg != '_')
	{
		put_export_arg_error_fd(((t_token *)tree->content)->token);
		return (1);
	}
	arg++;
	while (*arg && *arg != '=')
	{
		if (!ft_isalnum(*arg) && *arg != '_')
		{
			put_export_arg_error_fd(((t_token *)tree->content)->token);
			return (1);
		}
		arg++;
	}
	return (1);
}

static void	put_export_arg_error_fd(char *str)
{
	ft_putstr_fd("dish: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("\': not a valid identifier", 2);
}
