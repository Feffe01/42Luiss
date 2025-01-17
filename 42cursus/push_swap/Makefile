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


test-i-leaks-m: re
	@clear
	@echo ===== Mandatori =====
	-valgrind ./push_swap
	@echo
	-valgrind ./push_swap ""
	@echo
	-valgrind ./push_swap ''
	@echo
	-valgrind ./push_swap "   "
	@echo
	-valgrind ./push_swap 42 42
	@echo
	-valgrind ./push_swap Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./push_swap "Voglio mangiare il tuo pancreas"
	@echo
	-valgrind ./push_swap "Voglio mangiare il tuo pancreas" 42
	@echo
	-valgrind ./push_swap "42" Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./push_swap "++42"
	@echo
	-valgrind ./push_swap "--42"
	@echo
	-valgrind ./push_swap 1 "3" 2
	@echo
	-valgrind ./push_swap 1 "2 4" 3
	@echo
	-valgrind ./push_swap 1 "2 3" 2
	@echo
	-valgrind ./push_swap "''"
	@echo
	-valgrind ./push_swap '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-i-leaks-b: bonus
	@clear
	@echo ===== Bonus =====
	-valgrind ./checker
	@echo
	-valgrind ./checker ""
	@echo
	-valgrind ./checker ''
	@echo
	-valgrind ./checker "   "
	@echo
	-valgrind ./checker 42 42
	@echo
	-valgrind ./checker Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./checker "Voglio mangiare il tuo pancreas"
	@echo
	-valgrind ./checker "Voglio mangiare il tuo pancreas" 42
	@echo
	-valgrind ./checker "42" Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./checker "++42"
	@echo
	-valgrind ./checker "--42"
	@echo
	-valgrind ./checker 1 "3" 2
	@echo
	-valgrind ./checker 1 "2 4" 3
	@echo
	-valgrind ./checker 1 "2 3" 2
	@echo
	-valgrind ./checker "''"
	@echo
	-valgrind ./checker '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-i-nleaks-m: re
	@clear
	@echo ===== Mandatori =====
	-./push_swap
	@echo
	-./push_swap ""
	@echo
	-./push_swap ''
	@echo
	-./push_swap "   "
	@echo
	-./push_swap 42 42
	@echo
	-./push_swap Voglio mangiare il tuo pancreas
	@echo
	-./push_swap "Voglio mangiare il tuo pancreas"
	@echo
	-./push_swap "Voglio mangiare il tuo pancreas" 42
	@echo
	-./push_swap "42" Voglio mangiare il tuo pancreas
	@echo
	-./push_swap "++42"
	@echo
	-./push_swap "--42"
	@echo
	-./push_swap 1 "2" 3
	@echo
	-./push_swap 1 "2 4" 3
	@echo
	-./push_swap 1 "2 3" 2
	@echo
	-./push_swap "''"
	@echo
	-./push_swap '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-i-nleaks-b: bonus
	@clear
	@echo ===== Bonus =====
	-./checker
	@echo
	-./checker ""
	@echo
	-./checker ''
	@echo
	-./checker "   "
	@echo
	-./checker 42 42
	@echo
	-./checker Voglio mangiare il tuo pancreas
	@echo
	-./checker "Voglio mangiare il tuo pancreas"
	@echo
	-./checker "Voglio mangiare il tuo pancreas" 42
	@echo
	-./checker "42" Voglio mangiare il tuo pancreas
	@echo
	-./checker "++42"
	@echo
	-./checker "--42"
	@echo
	-./checker 1 "2" 3
	@echo
	-./checker 1 "2 4" 3
	@echo
	-./checker 1 "2 3" 2
	@echo
	-./checker "''"
	@echo
	-./checker '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

ARG_TESTER=$$(cat ./n.txt)

test-f100-leaks-m: re
	@clear 
	sh ./Assets_tester/Push_Swap/n_gen_100.sh
	@echo "Lista ordinata: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | wc -l
	@rm -f n.txt
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-f500-leaks-m: re
	@clear 
	sh ./Assets_tester/Push_Swap/n_gen_500.sh
	@echo "Lista ordinata: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | wc -l
	@rm -f n.txt
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-f100-nleaks-m: re
	@clear 
	sh ./Assets_tester/Push_Swap/n_gen_100.sh
	@echo "Lista ordinata: "
	@-./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-./$(NAME) $(ARG_TESTER) | wc -l
	@rm -f n.txt
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-f500-nleaks-m: re
	@clear 
	sh ./Assets_tester/Push_Swap/n_gen_500.sh
	@echo "Lista ordinata: "
	@-./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-./$(NAME) $(ARG_TESTER) | wc -l
	@rm -f n.txt
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-norm:
	@echo Errori di norma:
	@norminette *.c *.h | grep Error! | wc -l
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]


test-i-leaks-m: re
	@clear
	@echo ===== Mandatori =====
	-valgrind ./push_swap
	@echo
	-valgrind ./push_swap ""
	@echo
	-valgrind ./push_swap ''
	@echo
	-valgrind ./push_swap "   "
	@echo
	-valgrind ./push_swap 42 42
	@echo
	-valgrind ./push_swap Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./push_swap "Voglio mangiare il tuo pancreas"
	@echo
	-valgrind ./push_swap "Voglio mangiare il tuo pancreas" 42
	@echo
	-valgrind ./push_swap "42" Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./push_swap "++42"
	@echo
	-valgrind ./push_swap "--42"
	@echo
	-valgrind ./push_swap 1 "3" 2
	@echo
	-valgrind ./push_swap 1 "2 4" 3
	@echo
	-valgrind ./push_swap 1 "2 3" 2
	@echo
	-valgrind ./push_swap "''"
	@echo
	-valgrind ./push_swap '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-i-leaks-b: bonus
	@clear
	@echo ===== Bonus =====
	-valgrind ./checker
	@echo
	-valgrind ./checker ""
	@echo
	-valgrind ./checker ''
	@echo
	-valgrind ./checker "   "
	@echo
	-valgrind ./checker 42 42
	@echo
	-valgrind ./checker Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./checker "Voglio mangiare il tuo pancreas"
	@echo
	-valgrind ./checker "Voglio mangiare il tuo pancreas" 42
	@echo
	-valgrind ./checker "42" Voglio mangiare il tuo pancreas
	@echo
	-valgrind ./checker "++42"
	@echo
	-valgrind ./checker "--42"
	@echo
	-valgrind ./checker 1 "3" 2
	@echo
	-valgrind ./checker 1 "2 4" 3
	@echo
	-valgrind ./checker 1 "2 3" 2
	@echo
	-valgrind ./checker "''"
	@echo
	-valgrind ./checker '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-i-nleaks-m: re
	@clear
	@echo ===== Mandatori =====
	-./push_swap
	@echo
	-./push_swap ""
	@echo
	-./push_swap ''
	@echo
	-./push_swap "   "
	@echo
	-./push_swap 42 42
	@echo
	-./push_swap Voglio mangiare il tuo pancreas
	@echo
	-./push_swap "Voglio mangiare il tuo pancreas"
	@echo
	-./push_swap "Voglio mangiare il tuo pancreas" 42
	@echo
	-./push_swap "42" Voglio mangiare il tuo pancreas
	@echo
	-./push_swap "++42"
	@echo
	-./push_swap "--42"
	@echo
	-./push_swap 1 "2" 3
	@echo
	-./push_swap 1 "2 4" 3
	@echo
	-./push_swap 1 "2 3" 2
	@echo
	-./push_swap "''"
	@echo
	-./push_swap '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-i-nleaks-b: bonus
	@clear
	@echo ===== Bonus =====
	-./checker
	@echo
	-./checker ""
	@echo
	-./checker ''
	@echo
	-./checker "   "
	@echo
	-./checker 42 42
	@echo
	-./checker Voglio mangiare il tuo pancreas
	@echo
	-./checker "Voglio mangiare il tuo pancreas"
	@echo
	-./checker "Voglio mangiare il tuo pancreas" 42
	@echo
	-./checker "42" Voglio mangiare il tuo pancreas
	@echo
	-./checker "++42"
	@echo
	-./checker "--42"
	@echo
	-./checker 1 "2" 3
	@echo
	-./checker 1 "2 4" 3
	@echo
	-./checker 1 "2 3" 2
	@echo
	-./checker "''"
	@echo
	-./checker '""'
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

ARG_TESTER=$$(cat ./n.txt)

test-f100-leaks-m: re
	@clear 
	sh ./Assets_tester/Push_Swap/n_gen_100.sh
	@echo "Lista ordinata: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | wc -l
	@rm -f n.txt
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-f500-leaks-m: re
	@clear 
	sh ./Assets_tester/Push_Swap/n_gen_500.sh
	@echo "Lista ordinata: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-valgrind ./$(NAME) $(ARG_TESTER) | wc -l
	@rm -f n.txt
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-f100-nleaks-m: re
	@clear 
	sh ./Assets_tester/Push_Swap/n_gen_100.sh
	@echo "Lista ordinata: "
	@-./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-./$(NAME) $(ARG_TESTER) | wc -l
	@rm -f n.txt
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-f500-nleaks-m: re
	@clear 
	sh ./Assets_tester/Push_Swap/n_gen_500.sh
	@echo "Lista ordinata: "
	@-./$(NAME) $(ARG_TESTER) | ./Assets_tester/Push_Swap/checker $(ARG_TESTER)
	@echo "N. mosse: "
	@-./$(NAME) $(ARG_TESTER) | wc -l
	@rm -f n.txt
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

test-norm:
	@echo Errori di norma:
	@norminette *.c *.h | grep Error! | wc -l
	@echo
	@echo
	@echo TESTER AANGHI [Angly colui che regna]

