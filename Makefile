# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchernyu <mchernyu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 10:26:33 by mchernyu          #+#    #+#              #
#    Updated: 2022/01/09 08:20:01 by mchernyu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${patsubst %.c,%.o,${SRCS}}

HEADER=${patsubst %.c,%.d,${SRCS}}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

$(NAME): ${OBJS}
	ar rcs ${NAME} $?

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -MD

include ${wildcard ${HEADER}}

clean:
	rm -f ${OBJS} ${HEADER}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re