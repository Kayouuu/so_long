# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 13:55:52 by psaulnie          #+#    #+#              #
#    Updated: 2021/12/22 18:12:57 by psaulnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c parsing.c sprites.c
LIBFT = libft/
MLX = minilibx/
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = so_long

${NAME}: all

all: libft
		make -C ${MLX}
		mv minilibx/libmlx.dylib libmlx.dylib
		${CC} ${CFLAGS} -o so_long ${SRCS} libft.a libmlx.dylib

clean:
		rm -f ${OBJS}
		make -C ${LIBFT} clean
		make -C ${MLX} clean

fclean: clean
		rm -f ${NAME}
		rm -f libft.a
		rm -f libmlx.dylib
		make -C ${LIBFT} fclean
		make -C ${MLX} clean

re: fclean all

libft:
		make -C ${LIBFT}

.PHONY:	all clean fclean re libft
