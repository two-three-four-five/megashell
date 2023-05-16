/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/17 01:16:47 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "shell/type.h"

/*
* RULES for [e_token_type]

* enum with even number is not a token
* for example, UNDEFINED is not a TOKEN.
* for example, REDIRECT is not a token, but CATEGORY

* valid token has odd number.
* for example, a WORD is a valid token.
* for example, a PIPE is a valid token. 
*/

typedef enum e_token_type
{
	UNDEFINED = 0x0000,
	WORD = 0x0001,
	FILENAME = 0x0003,
	CMD = 0x0005,
	LOGIC = 0x0008,
	AND_IF = 0x0009,
	OR_IF = 0x000B,
	REDIRECT = 0x0010,
	LESS = 0x0011,
	DLESS = 0x0013,
	GREAT = 0x0015,
	DGREAT = 0x017,
	BRACKET = 0x0020,
	SUBSHELL = 0x0020,
	OPEN_PAREN = 0x0021,
	CLOSE_PAREN = 0x0023,
	META = 0x0040,
	PIPE = 0x0041,
	NEWLINE = 0x0043,
}	t_token_type;

typedef struct s_token
{
	char	type;
	char	*token;
}	t_token;

void	analyze_input(char *input, t_dict *env);

void	del_token_lstlast(t_list *lst);
void	del_token(void *ptr);
int		get_token_len(char *s);
char	get_token_type(char *s);
t_token	*get_next_token(char *s);
t_token	*new_token(char type, char *str);
void	print_token(void *ptr);
t_list	*tokenize(char *s);

t_bool	check_undefined_token(t_list *lst);
t_bool	check_matching_syntax(t_list *lst);
t_bool	check_token_order(t_list *lst);
t_bool	check_word_order(char prev, char curr);
t_bool	check_newline_order(char prev, char curr);
t_bool	check_operator_order(char prev, char curr);
t_bool	check_syntax(t_list *lst);

void	expand(t_list *lst, t_dict *env);
void	expand_tilde(t_list *lst, t_dict *env);
void	expand_parameter(t_list *lst, t_dict *env);
void	expand_filename(t_list *lst);
void	remove_quote(t_list *lst);
void	split_word(t_list *lst);

t_bool	redirect_heredoc(t_list *lst);

t_tree	*parse_lst(t_list *lst);

#endif