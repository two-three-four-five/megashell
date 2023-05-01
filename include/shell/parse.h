/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/01 14:43:35 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "shell/type.h"

typedef enum e_token_type
{
	UNDEFINED = -1,
	EOF = 0,
	WORD = 1,
	PIPE = 2,
	NEWLINE = 3,

	LOGIC = 4,
	AND_IF = 5,
	OR_IF = 6,

	REDIRECT = 8,
	LESS = 10,
	DLESS = 11,
	GREAT = 12,
	DGREAT = 13,

	BRACKET = 16,
	OPEN_PAREN = 18,
	CLOSE_PAREN = 19
}	t_token_type;



typedef struct s_token
{
	char	type;
	char	*token;
}	t_token;

void	del_token(void *ptr);
int		get_token_len(char *s);
char	get_token_type(char *s);
t_token	*get_next_token(char *s);
t_token	*new_token(char type, char *str);
t_list	*tokenize(char *s);

t_bool	check_quote(t_list *lst);
t_bool	check_parenthesis(t_list *lst);
t_bool	check_requirements(t_list *lst);
t_bool	check_syntax(t_list *lst);

#endif