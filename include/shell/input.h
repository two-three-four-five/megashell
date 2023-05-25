/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/05/26 02:35:32 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "libft.h"
# include "type.h"

/*
@ RULES for token.type

@ enum with even number is not a token
* for example, UNDEFINED is not a TOKEN.
* for example, REDIRECT is not a token, but CATEGORY

@ valid token has odd number.
* for example, a WORD is a valid token.
* for example, a PIPE is a valid token. 
*/

# define _HEAD 0x1000
# define UNDEFINED 0x0000

# define _CMD 0x0010
# define WORD 0x0013
# define FILENAME 0x0015
# define CMD 0x0019

# define _LOGIC 0x0020
# define AND_IF 0x0023
# define OR_IF 0x0025

# define _REDIRECT 0x0040
# define LESS 0x0043
# define DLESS 0x0045
# define _REDIRECT_OUT 0x0008
# define GREAT 0x004B
# define DGREAT 0x04D

# define _BRACKET 0x0080
# define _SUBSHELL 0x0080
# define OPEN_PAREN 0x0083
# define CLOSE_PAREN 0x0085

# define _META 0x0100
# define PIPE 0x0103
# define NL 0x0105

typedef struct s_token
{
	int		type;
	char	*token;
}	t_token;

//		expansion
void	expand_parameter_lst(t_list *lst, t_dict *env);
char	*expand_parameter_token(char *token, t_dict *env);
int		count_quote(char *token);
void	remove_quote_lst(t_list *lst);
char	*remove_quote_token(char *token);
void	expand_filename_lst(t_list *lst);
void	expand_tilde_lst(t_list *lst, t_dict *env);
void	split_word_lst(t_list *lst);
void	expand_lst(t_list *lst, t_dict *env);

//		parse
t_tree	*parse_command(t_list *lst);
t_tree	*parse_logic(t_list *lst);
t_tree	*parse_pipe(t_list *lst);
t_tree	*parse_subshell_with_redirect(t_list *lst);
t_tree	*parse_subshell(t_list *lst);
t_tree	*parse_lst(t_list *lst);

//		redirect
void	del_heredoc_tmp_files(t_tree *tree);
void	exec_heredoc(char *eof, int fd, t_dict *env);
t_bool	has_heredoc(t_list *lst);
t_bool	redirect_heredoc(t_list *lst, t_dict *env);
t_bool	wait_heredoc(pid_t pid, t_list *lst, char *filename, int fd);

//		syntax
t_bool	check_newline_order(int prev, int curr);
t_bool	check_word_order(int prev, int curr);
t_bool	check_operator_order(int prev, int curr);
t_bool	check_matching_syntax(t_list *lst);
t_bool	check_redirect_syntax(t_list *lst, t_dict *env);
t_bool	check_token_order(t_list *lst);
t_bool	check_undefined_token(t_list *lst);
t_bool	check_syntax(t_list *lst, t_dict *env);

//		token
void	del_token_lstlast(t_list *lst);
void	del_token(void *ptr);
t_token	*new_token(int type, char *str);
void	print_token(void *ptr);
t_token	*get_next_token(char *s);
int		get_token_len(char *s);
int		get_token_type(char *s);
t_list	*tokenize(char *s);

//		main
t_tree	*parse_input(char *input, t_dict *env);

#endif