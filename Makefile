# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 11:36:54 by kimkwanho         #+#    #+#              #
#    Updated: 2021/03/25 13:59:22 by kimkwanho        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

MAIN		=	minishell.c

SRCS		=	srcs/gnl.c \
				srcs/env.c \
				srcs/util_env1.c \
				srcs/signal.c \
				srcs/prompt.c \
				srcs/parse.c \
				srcs/exit.c \
				srcs/export.c \
				srcs/util1.c \
				srcs/util2.c \
				srcs/util3.c \
				srcs/util4.c
OBJS		=	${SRCS:.c=.o}

CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
# LIBFT		=	-L ./libft -lft

RM			=	rm -f

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

re : fclean all