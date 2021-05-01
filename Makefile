# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 11:36:54 by kimkwanho         #+#    #+#              #
#    Updated: 2021/05/01 22:20:26 by kimkwanho        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

MAIN		=	minishell.c

SRCS		=	srcs/cd.c \
				srcs/cursor.c \
				srcs/env.c \
				srcs/exit.c \
				srcs/export.c \
				srcs/init.c \
				srcs/key.c \
				srcs/exe.c \
				srcs/parse.c \
				srcs/builtin.c \
				srcs/prompt.c \
				srcs/pwd.c \
				srcs/echo.c \
				srcs/err.c \
				srcs/signal.c \
				srcs/util_env.c \
				srcs/util_exe.c \
				srcs/util1.c \
				srcs/util2.c \
				srcs/util3.c \
				srcs/util4.c \
				srcs/util5.c \
				srcs/util6.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f
MCHECK		=	-fsanitize=address

all : ${NAME}

$(NAME) : ${OBJS}
		@echo "\033[33m[Minishell compilation...]\033[0m"
		${CC} -lncurses ${MAIN} ${SRCS} -o ${NAME}
		@echo "\033[33m[Clean minishell...]\033[0m"
		${RM} ${OBJS}

.c.o :
		${CC} ${CCFLAGS} -c $< -o ${<:.c=.o}

clean :
		@echo "\033[33m[Clean minishell...]\033[0m"
		${RM} ${OBJS}

fclean : clean
		@echo "\033[33m[Fclean minishell...]\033[0m"
		${RM} ${NAME}

run : all
		@echo "\033[33m[Minishell start!]\033[0m"
		@echo "\033[33m---------------------------------------\033[0m"
		./$(NAME)

re : fclean all
