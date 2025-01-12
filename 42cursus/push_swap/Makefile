# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 17:56:06 by fgiampa           #+#    #+#              #
#    Updated: 2024/10/15 19:31:25 by fgiampa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re bonus

NAME = push_swap
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBRARIES = ${LIBFT}

BONUS :=		bonus.c
BONUS_OBJS :=	$(BONUS:.c=.o)
BONUS_BINS :=	$(BONUS:%.c=%)

SRCS :=			$(filter-out ${BONUS}, $(wildcard *.c))
OBJS :=			$(SRCS:.c=.o)
BINS :=			$(SRCS:%.c=%)

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	make -C libft
	${CC} ${OBJS} ${LIBRARIES} -o ${NAME}

clean:
	rm -rf ${OBJS} ${BONUS_OBJS}
	make clean -C libft

fclean: clean
	rm -rf ${BINS} ${NAME} ${BONUS_BINS}
	make fclean -C libft

re: fclean all

bonus: ${OBJS} ${BONUS_OBJS}
	make -C libft
	${CC} ${OBJS} ${BONUS_OBJS} ${LIBFT} -o ${NAME}

