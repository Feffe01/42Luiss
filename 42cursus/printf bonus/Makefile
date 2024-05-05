# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 18:20:11 by fgiampa           #+#    #+#              #
#    Updated: 2024/03/12 19:25:56 by fgiampa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS :=	$(wildcard *.c)
OBJS :=	$(SRCS:.c=.o)
BINS :=	$(SRCS:%.c=%)

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $^

${NAME}: ${OBJS}
	ar rcs $@ $^

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${BINS} ${NAME}

re:		fclean all
