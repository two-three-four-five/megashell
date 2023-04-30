# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/04/29 14:28:53 by gyoon            ###   ########.fr        #
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


# F_ERROR		= $(wildcard $(addprefix src/minishell/error/,	*.c))
# F_SIGNAL	= $(wildcard $(addprefix src/minishell/signal/, *.c))
# F_TOKEN		= $(wildcard $(addprefix src/minishell/token/,	*.c */*.c))
# F_TYPE		= $(wildcard $(addprefix src/minishell/type/,	*.c))
# F_MAIN		= src/minishell/main.c
SRCS		= $(wildcard	src/minishell/*.c		\
							src/minishell/*/*.c		\
							src/minishell/*/*/*.c	\
							src/minishell/*/*/*/*.c	\
							src/minishell/*/*/*/*/*.c)
OBJS 		= ${SRCS:.c=.o}
INCLUDE		= ./include

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

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -o $@ -lft -lreadline -L lib -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" 64)s" $(bar_done)
	@printf "%7.2f%%\n" 100
	@printf "🐚 Now you execute ${bold}$(MSHELL).${end}"
	@printf " (%s)\n" $(version)

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
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE) -I/opt/homebrew/opt/readline/include

clean :
	@$(RM) $(OBJS)
	@$(RM) $(B_OBJS)
	@printf "make clean ${bold}$(MSHELL).${end}\n"

fclean :
	@make clean
	@$(RM) $(NAME)
	@printf "make fclean ${bold}$(MSHELL).${end}\n"

re :
	@make fclean
	@printf "\n"
	@make all

.PHONY : all bonus clean fclean re
