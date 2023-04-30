/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/04/30 16:18:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"

int		get_operator_len(char *s);
char	*get_next_token(char *s);
t_list	*tokenize(char *s);

t_bool	check_quote(t_list *lst);
t_bool	check_parenthesis(t_list *lst);
t_bool check_requirements(t_list * lst);
t_bool	check_syntax(t_list *lst);

#endif