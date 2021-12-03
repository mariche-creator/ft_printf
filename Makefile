# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchernyu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 10:26:33 by mchernyu          #+#    #+#              #
#    Updated: 2021/12/01 22:38:08 by mariche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = ${SRCS:.C=.O}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJ}

all: ${NAME}

clean:
	rm -f ${OBJS} ${OBJSBONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all
