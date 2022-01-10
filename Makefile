# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 13:55:52 by psaulnie          #+#    #+#              #
#    Updated: 2022/01/10 09:47:29 by psaulnie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/parsing.c srcs/sprites.c srcs/update.c \
srcs/destroy.c srcs/handling.c srcs/input.c
BONUS_SRCS = srcs_bonus/animation_bonus.c srcs_bonus/destroy_bonus.c \
srcs_bonus/enemy_bonus.c srcs_bonus/handling_bonus.c srcs_bonus/input_bonus.c \
srcs_bonus/main_bonus.c srcs_bonus/parsing_bonus.c srcs_bonus/sprites_bonus.c \
srcs_bonus/update_bonus.c
LIBFT = libs/libft/
MLX = libs/minilibx/
CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = so_long

${NAME}: all

all: minilibx libft inc/so_long.h Makefile
		${CC} ${CFLAGS} -o so_long ${SRCS} ./libs/libft/libft.a libmlx.dylib

clean:
		rm -f ${OBJS}
		make -C ${LIBFT} clean
		make -C ${MLX} clean

fclean: clean
		rm -f ${NAME}
		rm -f libs/libft/libft.a
		rm -f libmlx.dylib
		make -C ${LIBFT} fclean
		make -C ${MLX} clean

re: fclean all

libft:
		make -C ${LIBFT}

minilibx:
		make -C ${MLX}
		mv libs/minilibx/libmlx.dylib libmlx.dylib

bonus: minilibx libft inc/so_long_bonus.h Makefile
		${CC} ${CFLAGS} -o so_long ${BONUS_SRCS} ./libs/libft/libft.a libmlx.dylib
	

.PHONY:	all clean fclean re libft minilibx bonus
