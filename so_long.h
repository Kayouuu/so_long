/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:27:19 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/22 17:20:21 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define SPRITE0 0
# define SPRITE1 1
# define SPRITE2 2
# define SPRITE3 3
# define SPRITE4 4
# define SPRITE5 5
# define SPRITE6 6
# define SPRITE7 7
# define CHEST 8
# define GRASS 9
# define TREE 10
# define COIN 11

typedef enum e_type
{
	WALL,
	COLLECTIBLE,
	SPACE,
	PLAYER,
	EXIT
}				t_type;

typedef struct s_size {
	int	width;
	int	height;
}				t_size;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

typedef struct s_img {
	void	*img;
	char	*addr;
	char	*relative_path;
	t_size	size;
	t_pos	position;
	t_type	type;
}				t_img;

/*	MAIN.C	*/

/*	PARSING.C	*/

char	**parsing(char *map);

/*	SPRITES.C	*/

void	draw_map(t_mlx mlx, char **sprites, char **map);
char	**get_sprites(void *mlx);

#endif