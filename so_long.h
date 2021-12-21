/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:27:19 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/21 14:38:36 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef enum e_type
{
	WALL,
	COLLECTIBLE,
	SPACE,
	PLAYER
}				t_type;

typedef struct s_size {
	int	width;
	int	height;
}				t_size;

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

#endif