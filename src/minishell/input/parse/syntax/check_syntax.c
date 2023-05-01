/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:05:20 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/01 14:23:58 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell/type.h"
#include "shell/parse.h"
#include <stdio.h>

// t_bool	check_requirements(t_list *lst)
// {
// 	char	*previous_token;

// 	previous_token = NULL;
// 	while (lst)
// 	{
// 		if (!ft_strncmp(lst->content, "&&", 2) || \
// 			!ft_strncmp(lst->content, "||", 2) || \
// 			!ft_strncmp(lst->content, "|", 1))
// 		{
// 			if (!previous_token || !lst->next)
// 			{
// 				printf("dish: syntax error near unexpected token `%s\'\n", \
// 						(char *)lst->content);
// 				return (FALSE);
// 			}
// 			else if (!ft_strncmp(lst->next->content, "\n", 1))
// 			{
// 				printf("dish: syntax error near unexpected token `%s\'\n", \
// 						"newline");
// 				return (FALSE);
// 			}
// 		}
// 		else if (!ft_strncmp(lst->content, ";", 1))
// 		{
// 			if (!previous_token || get_operator_len(previous_token))
// 			{
// 				printf("dish: syntax error near unexpected token `%s\'\n", \
// 						(char *)lst->content);
// 				return (FALSE);
// 			}
// 		}
// 		else if (!ft_strncmp(lst->content, "<<", 2) || \
// 				!ft_strncmp(lst->content, ">>", 2) || \
// 				!ft_strncmp(lst->content, "<", 1) || \
// 				!ft_strncmp(lst->content, ">", 1))
// 		{
// 			if (!lst->next)
// 			{
// 				printf("dish: syntax error near unexpected token `%s\'\n", \
// 						(char *)lst->content);
// 				return (FALSE);
// 			}
// 			else if (!ft_strncmp(lst->next->content, "<<", 2) || \
// 					!ft_strncmp(lst->next->content, ">>", 2) || \
// 					!ft_strncmp(lst->next->content, "<", 1) || \
// 					!ft_strncmp(lst->next->content, ">", 1))
// 			{
// 				printf("dish: syntax error near unexpected token `%s\'\n", \
// 						(char *)lst->next->content);
// 				return (FALSE);
// 			}
// 			else if (!ft_strncmp(lst->next->content, "\n", 1))
// 			{
// 				printf("dish: syntax error near unexpected token `%s\'\n", \
// 						"newline");
// 				return (FALSE);
// 			}
// 		}
// 		previous_token = lst->content;
// 		lst = lst->next;
// 	}
// 	return (TRUE);

// }

// t_bool	check_syntax(t_list *lst)
// {
// 	if (!check_quote(lst))
// 		return (FALSE);
// 	else if (!check_parenthesis(lst))
// 		return (FALSE);
// 	else if (!check_requirements(lst))
// 		return (FALSE);
// 	else
// 		return (TRUE);
// }
