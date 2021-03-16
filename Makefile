# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 11:36:54 by kimkwanho         #+#    #+#              #
#    Updated: 2021/03/16 23:56:56 by kimkwanho        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

MAIN		=	minishell.c
SRCS		=	srcs/get_next_line.c
OBJS		=	${SRCS:.c=.o}

CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
LIBFT		=	-L ./libft -lft

RM			=	rm -f

all : ${NAME}

$(NAME) : ${OBJS}
		@echo "\033[33m[Libft compilation : bonus...]\033[0m"
		@${MAKE} -C ./libft bonus
		@echo "\033[33m[Minishell compilation...]\033[0m"
		${CC} ${MAIN} ${SRCS} ${LIBFT} -o ${NAME}
		@echo "\033[33m[Fclean libft...]\033[0m"
		@${MAKE} -C ./libft fclean
		@echo "\033[33m[Clean minishell...]\033[0m"
		${RM} ${OBJS}

.c.o :
		${CC} ${CCFLAGS} -c $< -o ${<:.c=.o}

clean :
		@echo "\033[33m[Clean libft...]\033[0m"
		${MAKE} -C ./libft clean
		@echo "\033[33m[Clean minishell...]\033[0m"
		${RM} ${OBJS}

fclean : clean
		@echo "\033[33m[Fclean libft...]\033[0m"
		${MAKE} -C ./libft fclean
		@echo "\033[33m[Fclean minishell...]\033[0m"
		${RM} ${NAME}

re : fclean all