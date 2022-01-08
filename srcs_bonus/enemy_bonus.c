/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:52:44 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/08 15:26:37 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static t_pos	*enemy_pos_finder(t_data data, int counter)
{
	t_pos	pos;
	t_pos	*enemy_pos;

	enemy_pos = malloc(sizeof(t_pos) * (data.enemy_nbr + 1));
	if (!enemy_pos)
		destroy(0, &data);
	pos.y = 0;
	while (data.map.map[pos.y])
	{
		pos.x = 0;
		while (data.map.map[pos.y][pos.x])
		{
			if (data.map.map[pos.y][pos.x] == 'A')
			{
				enemy_pos[counter].x = pos.x;
				enemy_pos[counter].y = pos.y;
				counter++;
			}
			pos.x++;
		}
		pos.y++;
	}
	enemy_pos[counter].x = 0;
	return (enemy_pos);
}

static t_pos	*get_pos_pos(t_data data)
{
	t_pos	*enemy_pos;
	int		counter;

	if (data.enemy != 0)
		free(data.enemy_pos);
	counter = 0;
	enemy_pos = enemy_pos_finder(data, counter);
	return (enemy_pos);
}

static int	check(char c, t_data *data, int i)
{
	if (c == 'P')
	{
		printf("Game Over !\n");
		data->map.map[data->enemy_pos[i].y][data->enemy_pos[i].x] = 'B';
		update_map(data->map.map_backup, data->map.map,
			data->map.sprites, data->mlx);
		data->map.map_backup = backup_map(&*data);
		mlx_key_hook(data->mlx.mlx_win, destroy, &*data);
		mlx_hook(data->mlx.mlx_win, 17, 1L << 0, destroy_mouse, &*data);
		mlx_loop(data->mlx.mlx);
		return (1);
	}
	else if (c != 'E' && c != '1' && c != 'C' && c != 'A')
		return (1);
	return (0);
}

void	enemy_movement(t_data *data, int i)
{
	int		direction;
	int		as_moved;
	int		y;
	int		x;

	direction = rand() % 4;
	y = data->enemy_pos[i].y;
	x = data->enemy_pos[i].x;
	as_moved = 1;
	if (check(data->map.map[y][x - 1], &*data, i) && direction == 0)
		data->map.map[y][x - 1] = 'A';
	else if (check(data->map.map[y][x + 1], &*data, i) && direction == 1)
		data->map.map[y][x + 1] = 'A';
	else if (check(data->map.map[y + 1][x], &*data, i) && direction == 2)
		data->map.map[y + 1][x] = 'A';
	else if (check(data->map.map[y - 1][x], &*data, i) && direction == 3)
		data->map.map[y - 1][x] = 'A';
	else
		as_moved = 0;
	if (as_moved)
		data->map.map[y][x] = '0';
	update_map(data->map.map_backup, data->map.map,
		data->map.sprites, data->mlx);
	data->map.map_backup = backup_map(&*data);
}

int	enemy(t_data *data)
{
	int	i;

	if (data->enemy_nbr > 0)
	{
		data->enemy_pos = get_pos_pos(*data);
		data->enemy = 1;
		i = 0;
		while (data->enemy_pos[i].x != 0)
		{
			enemy_movement(data, i);
			i++;
		}
	}
	return (0);
}
