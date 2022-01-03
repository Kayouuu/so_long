/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:52:44 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/03 15:57:24 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_pos	*get_enemy_pos(t_data data)
{
	t_pos	*enemy_pos;
	t_pos	pos;
	int		counter;

	if (data.enemy_pos != NULL)
		free(data.enemy_pos);
	enemy_pos = malloc(sizeof(t_pos) * (data.enemy_nbr + 1));
	pos.y = 0;
	counter = 0;
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

static int	check(char c)
{
	if (c != 'E' && c != '1' && c != 'C')
		return (1);
	if (c == 'P')
		printf("Game Over !");
	return (0);
}

void	enemy_movement(t_data *data, int i)
{
	int	as_moved;

	as_moved = 1;
	if (check(data->map.map[data->enemy_pos[i].y - 1][data->enemy_pos[i].x]))
		data->map.map[data->enemy_pos[i].y - 1][data->enemy_pos[i].x] = 'A';
	else if (check(data->map.map[data->enemy_pos[i].y + 1][data->enemy_pos[i].x]))
		data->map.map[data->enemy_pos[i].y + 1][data->enemy_pos[i].x] = 'A';
	else if (check(data->map.map[data->enemy_pos[i].y][data->enemy_pos[i].x - 1]))
		data->map.map[data->enemy_pos[i].y][data->enemy_pos[i].x - 1] = 'A';
	else if (check(data->map.map[data->enemy_pos[i].y][data->enemy_pos[i].x + 1]))
		data->map.map[data->enemy_pos[i].y][data->enemy_pos[i].x + 1] = 'A';
	else
		as_moved = 0;
	if (as_moved)
	{
		data->map.map[data->enemy_pos[i].y][data->enemy_pos[i].x] = '0';
	}
	update_map(data->map.map_backup, data->map.map,
		data->map.sprites, data->mlx);
	data->map.map_backup = backup_map(data->map.map);
}

int	enemy(t_data *data)
{
	int	i;

	if (data->enemy_nbr > 0)
	{
		data->enemy_pos = get_enemy_pos(*data);
		i = 0;
		while (data->enemy_pos[i].x != 0)
		{
			enemy_movement(data, i);
			i++;
		}
	}
	return (0);
}
