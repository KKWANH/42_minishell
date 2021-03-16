# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjh399 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 10:22:02 by pjh399            #+#    #+#              #
#    Updated: 2021/03/15 11:59:01 by pjh399           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN = main.c
SRCS = get_next_line.c 
OBJS = ${SRCS:.c=.o}
NAME = minishell
cc = gcc
RM = rm -f
MCHECK = -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
LIBFT = -L ./libft -lft

all : ${NAME}

$(NAME) : ${OBJS}
	@${MAKE} -C ./libft bonus
	${CC} ${MAIN} ${SRCS} ${LIBFT} -o ${NAME}

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}	

clean :
	@${MAKE} -C ./libft clean
	${RM} ${OBJS}

fclean : clean
	@${MAKE} -C ./libft fclean
	${RM} ${NAME}

re : fclean all
