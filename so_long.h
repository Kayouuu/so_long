/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:27:19 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/06 10:25:05 by psaulnie         ###   ########.fr       */
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
# define CHEST 6
# define GRASS 7
# define TREE 8
# define COIN 9
# define ENEMY 10

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53

typedef struct s_map
{
	char	**map;
	char	**map_backup;
	void	**sprites;
}				t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

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

void	free_tab(char **tab);
int		destroy_mouse(t_data *data);
int		destroy(int key, t_data *data);

/*	ENEMY.C	*/

int		enemy(t_data *data);

/*	HANDLING.C	*/

void	check_map_error(t_data *data);

/*	INPUT.C	*/

void	check_exit(t_data data, int key, t_pos	player);
int		input(int key, t_data *data);

/*	PARSING.C	*/

char	**parsing(char *map);

/*	SPRITES.C	*/

void	draw(char obj, t_pos pos, void **sprites, t_mlx mlx);
void	draw_map(t_mlx mlx, void **sprites, char **map);
void	**get_sprites(t_data *data);

/*	UPDATE.C	*/

void	get_player_pos(t_pos *player, char **map);
void	update_map(char **old_map, char **map, void **sprites, t_mlx mlx);
char	**backup_map(t_data *data);

#endif