# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 11:36:54 by kimkwanho         #+#    #+#              #
#    Updated: 2021/04/08 16:59:47 by kimkwanho        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

MAIN		=	minishell.c

SRCS		=	srcs/env.c \
				srcs/exit.c \
				srcs/gnl.c \
				srcs/parse.c \
				srcs/process.c \
				srcs/prompt.c \
				srcs/signal.c \
				srcs/util_env.c \
				srcs/util1.c \
				srcs/util2.c \
				srcs/util3.c \
				srcs/util4.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f
MCHECK		=	-fsanitize=address

all : ${NAME}

$(NAME) : ${OBJS}
		@echo "\033[33m[Minishell compilation...]\033[0m"
		${CC} ${MAIN} ${SRCS} -o ${NAME}
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
