/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/08 21:42:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "shell/type.h"

typedef enum e_token_type
{
	UNDEFINED = 0x0000,
	WORD = 0x0001,
	FILENAME = 0x0003,
	PIPE = 0x0005,
	NEWLINE = 0x0007,

	LOGIC = 0x0008,
	AND_IF = 0x0009,
	OR_IF = 0x000B,

	REDIRECT = 0x0010,
	LESS = 0x0011,
	DLESS = 0x0013,
	GREAT = 0x0015,
	DGREAT = 0x017,

	BRACKET = 0x0020,
	OPEN_PAREN = 0x0021,
	CLOSE_PAREN = 0x0023
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

t_bool	check_matching_syntax(t_list *lst);
t_bool	check_token_syntax(t_list *lst);
t_bool	check_undefined_token(t_list *lst);
t_bool	check_syntax(t_list *lst);

void	expand(t_list **lst, t_dict *env);
void	expand_parameter(t_list *lst, t_dict *env);
void	expand_filename(t_list *lst);
void	remove_quote(t_list *lst);

#endif