/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:29:37 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/27 12:03:37 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_obj *player, char **map)
{
	int     x;
	int     y;

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
	player->pos.x = x;
	player->pos.y = y;
}

void	update_map(char **old_map, char **map, char **sprites, t_mlx mlx)
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
		pos.y++;
	}
	free(old_map);
}

char	**backup_map(char **map)
{
	char	**backup;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (map[len])
		len++;
	backup = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		backup[i] = ft_strdup(map[i]);
		i++;
	}
	backup[i] = NULL;
	return (backup);
}
