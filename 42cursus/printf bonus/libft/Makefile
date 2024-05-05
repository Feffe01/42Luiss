# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 18:20:11 by fgiampa           #+#    #+#              #
#    Updated: 2024/02/27 16:38:59 by fgiampa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re bonus

NAME = libft.a
header = libft.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

BONUS :=		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS :=	$(BONUS:.c=.o)
BONUS_BINS :=	$(BONUS:%.c=%)

SRCS :=			$(filter-out ${BONUS}, $(wildcard *.c))
OBJS :=			$(SRCS:.c=.o)
BINS :=			$(SRCS:%.c=%)

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $^ -I $(header)

${NAME}: ${OBJS}
	ar rcs $@ $^

clean:
	rm -rf ${OBJS} ${BONUS_OBJS}

fclean:	clean
	rm -rf ${BINS} ${BONUS_BINS}

re:		fclean all

bonus:	$(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
