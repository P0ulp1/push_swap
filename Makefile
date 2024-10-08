# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: p0ulp1 <p0ulp1@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 12:24:27 by phautena          #+#    #+#              #
#    Updated: 2024/07/22 11:37:59 by p0ulp1           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = ./srcs/main.c ./srcs/linked_lists.c ./srcs/parsing.c ./srcs/push_swap_utils.c \
		./srcs/instructions/swap.c ./srcs/instructions/push.c ./srcs/instructions/rotate.c \
		./srcs/instructions/reverse_rotate.c ./srcs/algorithms/radix_algo.c \
		./srcs/algorithms/radix_utils.c


CC = cc -Wall -Werror -Wextra -ggdb -g -I./includes/

OBJ = ${SRC:.c=.o}

LIBFT_ARCHIVE = ./Libft/libft.a

PRINTF_ARCHIVE = ./ft_printf/libftprintf.a

.c.o:
	${CC} -c $< -o $@

all: ${NAME}

${NAME}: ${LIBFT_ARCHIVE} ${PRINTF_ARCHIVE} ${OBJ}
	${CC} ${OBJ} ${LIBFT_ARCHIVE} ${PRINTF_ARCHIVE} -o ${NAME}

${LIBFT_ARCHIVE}:
	make -sC ./Libft

${PRINTF_ARCHIVE}:
	make -sC ./ft_printf

clean:
	make clean -sC ./Libft
	make clean -sC ./ft_printf
	rm -f ${OBJ}

fclean: clean
	make fclean -sC ./Libft
	make fclean -sC ./ft_printf
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re