# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/05/26 20:23:28 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
MSHELL	= megashell

# **************************************************************************** #
#                                                                              #
#    Options                                                                   #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# **************************************************************************** #
#                                                                              #
#    Source Files                                                              #
#                                                                              #
# **************************************************************************** #

SRCS		= src/main.c src/shell/command/execute.c src/shell/command/execute/builtin/execute_builtin.c src/shell/command/execute/builtin/execute_cd.c src/shell/command/execute/builtin/execute_echo.c src/shell/command/execute/builtin/execute_env.c src/shell/command/execute/builtin/execute_exit.c src/shell/command/execute/builtin/execute_export.c src/shell/command/execute/builtin/execute_pwd.c src/shell/command/execute/builtin/execute_unset.c src/shell/command/execute/builtin/export/execute_export_nop.c src/shell/command/execute/builtin/export/execute_export_op.c src/shell/command/execute/builtin/export/raise_export_arg_error.c src/shell/command/execute/builtin/export/raise_export_usage_error.c src/shell/command/execute/execute_and_if.c src/shell/command/execute/execute_cmd.c src/shell/command/execute/execute_in_child.c src/shell/command/execute/execute_or_if.c src/shell/command/execute/execute_pipe.c src/shell/command/execute/execute_subshell.c src/shell/command/execute/redirect/redirect_fd.c src/shell/command/substitute_command_tree.c src/shell/command/utils/get_argv.c src/shell/command/utils/get_exit_status.c src/shell/command/utils/is_builtin_cmd.c src/shell/command/utils/is_directory.c src/shell/command/utils/is_executable.c src/shell/command/utils/is_file_exist.c src/shell/envp/get_envp.c src/shell/envp/get_envp_dict.c src/shell/error/raise_cd_error.c src/shell/error/raise_cmd_error.c src/shell/error/raise_exit.c src/shell/error/raise_exit_error.c src/shell/error/raise_file_error.c src/shell/error/raise_redirect_error.c src/shell/error/raise_syntax_error.c src/shell/execute_shell.c src/shell/input/expansion/expand/expand_filename_lst.c src/shell/input/expansion/expand/expand_tilde_lst.c src/shell/input/expansion/expand/parameter/expand_parameter_lst.c src/shell/input/expansion/expand/parameter/expand_parameter_token.c src/shell/input/expansion/expand/quote/count_quote.c src/shell/input/expansion/expand/quote/remove_quote_lst.c src/shell/input/expansion/expand/quote/remove_quote_token.c src/shell/input/expansion/expand/split_word_lst.c src/shell/input/expansion/expand_lst.c src/shell/input/parse/parse_lst.c src/shell/input/parse/parse_lst/parse_command.c src/shell/input/parse/parse_lst/parse_logic.c src/shell/input/parse/parse_lst/parse_pipe.c src/shell/input/parse/parse_lst/parse_subshell.c src/shell/input/parse/parse_lst/parse_subshell_with_redirect.c src/shell/input/parse_input.c src/shell/input/redirection/heredoc/del_heredoc_tmp_files.c src/shell/input/redirection/heredoc/exec_heredoc.c src/shell/input/redirection/heredoc/has_heredoc.c src/shell/input/redirection/heredoc/redirect_heredoc.c src/shell/input/redirection/heredoc/wait_heredoc.c src/shell/input/syntax/check/check_matching_syntax.c src/shell/input/syntax/check/check_redirect_syntax.c src/shell/input/syntax/check/check_token_order.c src/shell/input/syntax/check/check_undefined_token.c src/shell/input/syntax/check/order/check_newline_order.c src/shell/input/syntax/check/order/check_operator_order.c src/shell/input/syntax/check/order/check_word_order.c src/shell/input/syntax/check_syntax.c src/shell/input/token/del/del_token.c src/shell/input/token/del/del_token_lstlast.c src/shell/input/token/new/new_token.c src/shell/input/token/print/print_token.c src/shell/input/token/tokenize.c src/shell/input/token/tokenize/get_next_token.c src/shell/input/token/tokenize/get_token_len.c src/shell/input/token/tokenize/get_token_type.c src/shell/signal/handle_sigint.c src/shell/signal/handle_sigint_in_execution.c src/shell/signal/set_signal_handler.c src/type/dict/get_dict_value.c src/type/dict/has_dict_key.c src/type/dict/reassign_dict_value.c src/type/isdelimeter.c src/type/ismeta.c src/type/isoperator.c src/type/isquote.c src/type/str_pair/del_str_pair.c src/type/str_pair/dup_str_pair.c src/type/str_pair/dup_str_pair_s1.c src/type/str_pair/new_str_pair.c src/type/str_pair/print_str_pair.c src/type/string/del_strp.c src/type/string/ft_atoll.c src/type/string/ft_strcmp.c src/type/tree/ft_treeadd_leftend.c src/type/tree/ft_treeadd_rightend.c src/type/tree/ft_treeclear.c src/type/tree/ft_treeleftsize.c src/type/tree/ft_treenew.c src/type/tree/print_tree.c

BONUS_SRCS	= ${SRCS:.c=_bonus.c}
M_OBJS 		= $(addprefix mandatory/, ${SRCS:.c=.o})
B_OBJS		= $(addprefix bonus/, ${BONUS_SRCS:.c=.o})
INC			= ./include

ifdef BONUS
	OBJS = $(B_OBJS)
	INCLUDE = $(addprefix bonus/, $(INC)) 
else
	OBJS = $(M_OBJS)
	INCLUDE = $(addprefix mandatory/, $(INC)) 
endif

LIBFT		= ./lib/libft.a
READLINE	= ~/.brew/opt/readline

# **************************************************************************** #
#                                                                              #
#    Progress                                                                  #
#                                                                              #
# **************************************************************************** #

num_file	= $(shell echo $(SRCS) | tr ' ' '\n' | wc -w)
cnt			:= 0
bar_done	= '🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩'
bar_ready	= '⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️'

#			COLOR
red			= \e[1;31m
grn			= \e[1;32m
yel			= \e[1;33m
blu			= \e[1;34m
mag			= \e[1;35m
cyn			= \e[1;36m
bold		= \e[1;37m
end			= \e[0m

version = "mandatory version"

# **************************************************************************** #
#                                                                              #
#    Executable Section                                                        #
#                                                                              #
# **************************************************************************** #

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -o $@ -lft -lreadline -L lib -L $(READLINE)/lib
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" 64)s" $(bar_done)
	@printf "%7.2f%%\n" 100
	@printf "🐚 Now you execute ${bold}$(MSHELL).${end}"
	@printf " (%s)\n" $(version)

bonus : 
	make BONUS=1 all

$(LIBFT) :
	@printf "make ${bold}LIBFT.${end}\n"
	@make -C ./lib/libft
	@cp ./lib/libft/libft.a ./lib/libft.a

%.o : %.c
	@$(eval cnt=$(shell printf $$(($(cnt)+1))))
	@$(eval rate_hex=$(shell echo "scale=2; ($(cnt) / $(num_file)) * 16" | bc))
	@$(eval len=$(shell printf "%.0f\n" $(rate_hex)))
	@$(eval len_done=$(shell echo "scale=0; $(len) * 4" | bc))
	@$(eval len_ready=$(shell echo "scale=0; 96 - ($(len_done) / 4) * 6" | bc))
	@$(eval percent=$(shell echo "scale=4; ($(cnt) / $(num_file)) * 100" | bc))
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" $(len_done))s" $(bar_done)
	@printf "%.$(shell printf "%d" $(len_ready))s" $(bar_ready)
	@printf "%7.2f%%" $(percent)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE) -I $(READLINE)/include

clean :
	@$(RM) $(M_OBJS)
	@$(RM) $(B_OBJS)
	@make clean -C ./lib/libft
	@printf "make clean ${bold}$(MSHELL).${end}\n"

fclean :
	@make clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@make fclean -C ./lib/libft
	@printf "make fclean ${bold}$(MSHELL).${end}\n"

re :
	@make fclean
	@printf "\n"
	@make all

.PHONY : all bonus clean fclean re
