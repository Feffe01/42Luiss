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

NAME = so_long
LIBFT = libft/libft.a
MLX = ./minilibx-linux/

CC = cc
CFLAGS = -Wall -Wextra -Werror -lm
MLXFLAGS = -L ${MLX} -lmlx -I${MLX} -lXext -lX11
LIBRARIES = ${LIBFT}

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
	${CC} ${CFLAGS} -I${MLX} -c $< -o $@

${NAME}: ${OBJS}
	make -C ${MLX}
	make -C libft
	${CC} ${OBJS} ${LIBRARIES} ${MLXFLAGS} -o ${NAME}

clean:
	rm -rf ${OBJS} ${BONUS_OBJS}
	make clean -C libft

fclean: clean
	rm -rf ${BINS} ${NAME} ${BONUS_BINS}
	make clean -C ${MLX}
	make fclean -C libft

re: fclean all

bonus: ${OBJS} ${BONUS_OBJS}
	make -C ${MLX}
	make -C libft
	${CC} ${OBJS} ${BONUS_OBJS} ${LIBFT} ${MLXFLAGS} -o ${NAME}

