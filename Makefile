# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agogolev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 16:36:50 by agogolev          #+#    #+#              #
#    Updated: 2021/07/15 13:38:34 by emgarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./src/ft_library1.c \
		  ./src/ft_library2.c \
		  ./src/solve.c \
		  ./src/algorithm.c \
		  ./src/ft_valid_map.c \
		  ./src/main.c
OBJS	=${SRCS:.c=.o}
INCS	= ./header
NAME	= bsq
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME} :${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all :
	${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

norm :
	norminette */*.[ch]

re : fclean all

.PHONY: all clean fclean re
