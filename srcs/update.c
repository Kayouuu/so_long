/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:29:37 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/17 12:52:44 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_player_pos(t_pos *player, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				break ;
			x++;
		}
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	player->x = x;
	player->y = y;
}

void	update_map(char **old_map, char **map, void **sprites, t_mlx mlx)
{
	t_pos	pos;
	t_pos	backup;

	pos.y = 0;
	while (old_map[pos.y])
	{
		pos.x = 0;
		while (old_map[pos.y][pos.x])
		{
			if (old_map[pos.y][pos.x] != map[pos.y][pos.x])
			{
				backup.x = pos.x;
				backup.y = pos.y;
				pos.x *= 63;
				pos.y *= 63;
				draw(map[backup.y][backup.x], pos, sprites, mlx);
				pos.x = backup.x;
				pos.y = backup.y;
			}
			pos.x++;
		}
		free(old_map[pos.y]);
		pos.y++;
	}
	free(old_map);
}

char	**backup_map(t_data *data)
{
	char	**backup;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (data->map.map[len])
		len++;
	backup = malloc(sizeof(char *) * (len + 1));
	if (!backup)
		destroy(0, &*data);
	while (i < len)
	{
		backup[i] = ft_strdup(data->map.map[i]);
		if (!backup[i])
		{
			printf("Error\nMalloc error\n");
			destroy(0, &*data);
		}
		i++;
	}
	backup[i] = NULL;
	return (backup);
}
