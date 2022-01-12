# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 13:55:52 by psaulnie          #+#    #+#              #
#    Updated: 2022/01/12 15:36:50 by psaulnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/parsing.c srcs/sprites.c srcs/update.c \
srcs/destroy.c srcs/handling.c srcs/input.c
OBJS = ${SRCS:.c=.o}
BONUS_SRCS = srcs_bonus/animation_bonus.c srcs_bonus/destroy_bonus.c \
srcs_bonus/enemy_bonus.c srcs_bonus/handling_bonus.c srcs_bonus/input_bonus.c \
srcs_bonus/main_bonus.c srcs_bonus/parsing_bonus.c srcs_bonus/sprites_bonus.c \
srcs_bonus/update_bonus.c
OBJS_BONUS = ${BONUS_SRCS:.c=.o}
LIBFT = libs/libft/
LIBFT_LIB = libs/libft/libft.a
MLX = libs/minilibx/
MLX_LIB = libmlx.dylib
CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = so_long
NAME_BONUS = so_long_bonus

.PHONY:	all clean fclean re bonus

all: ${NAME}

${NAME}: ${OBJS} ${MLX_LIB} ${LIBFT_LIB} inc/so_long.h Makefile
		${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} -o ${NAME}

clean:
		rm -f ${OBJS}
		rm -f ${OBJS_BONUS}
		make  -s -C ${LIBFT} clean
		make -s -C ${MLX} clean

fclean: clean
		rm -f ${NAME} ${NAME_BONUS} ${LIBFT_LIB} ${MLX_LIB}
		make -s -C ${LIBFT} fclean
		make -s -C ${MLX} clean

re: fclean all

${LIBFT_LIB}:
		make -C ${LIBFT}

${MLX_LIB}:
		make -C ${MLX}
		mv libs/minilibx/libmlx.dylib libmlx.dylib

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS} ${MLX_LIB} ${LIBFT_LIB} inc/so_long_bonus.h Makefile
		${CC} ${CFLAGS} ${OBJS_BONUS} ${LIBFT_LIB} ${MLX_LIB} -o ${NAME_BONUS}

