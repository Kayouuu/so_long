/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:27:19 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/20 13:52:35 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft/libft.h"

# include <stdlib.h>
# include <fcntl.h>

typedef enum e_type	t_type
{
	WALL,
	COLLECTIBLE,
	SPACE,
	PLAYER
};

typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

typedef struct s_img {
	void	*img;
	char	*addr;
	char	*relative_path;
	int		width;
	int		height;
	t_pos	position;
	e_type	type;
}				t_img;

#endif