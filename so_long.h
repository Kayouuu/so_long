/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:27:19 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/03 15:37:37 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define SPRITE0 0
# define CHEST 6
# define GRASS 7
# define TREE 8
# define COIN 9
# define ENEMY 10

# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_SPACE 32

typedef struct s_map
{
	char	**map;
	char	**map_backup;
	char	**sprites;
}				t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

typedef struct s_obj {
	t_pos	pos;
}				t_obj;

typedef struct s_data
{
	t_map	map;
	t_mlx	mlx;
	t_pos	*enemy_pos;
	int		total_coin;
	int		current_coin;
	int		movement;
	int		enemy_nbr;
}				t_data;

/*	ANIMATION.C	*/

int		anim(int key, t_data *data);

/*	DESTROY.C	*/

int		destroy_mouse(t_data *data);
int		destroy(int key, t_data *data);

/*	ENEMY.C	*/

int		enemy(t_data *data);

/*	HANDLING.C	*/

void	check_map_error(char **map);

/*	INPUT.C	*/

void	check_exit(t_data data, int key, t_obj	player);
int		input(int key, t_data *data);

/*	PARSING.C	*/

char	**parsing(char *map);

/*	SPRITES.C	*/

void	draw(char obj, t_pos pos, char **sprites, t_mlx mlx);
void	draw_map(t_mlx mlx, char **sprites, char **map);
char	**get_sprites(void *mlx);

/*	UPDATE.C	*/

void	get_player_pos(t_obj *player, char **map);
void	update_map(char **old_map, char **map, char **sprites, t_mlx mlx);
char	**backup_map(char **map);

#endif