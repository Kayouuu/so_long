/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:00:33 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/27 12:10:10 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input(int key, t_data *data)
{
	t_obj	player;

	player.pos.x = 0;
	player.pos.y = 0;
	if (key == 119 || key == 87)
	{
		get_player_pos(&player, data->map.map);
		data->map.map[player.pos.y - 1][player.pos.x] = 'P';
		data->map.map[player.pos.y][player.pos.x] = '0';
	}
	else if (key == 97 || key == 65)
	{
		get_player_pos(&player, data->map.map);
		data->map.map[player.pos.y][player.pos.x - 1] = 'P';
		data->map.map[player.pos.y][player.pos.x] = '0';
	}
	else if (key == 100 || key == 68)
	{
		get_player_pos(&player, data->map.map);
		data->map.map[player.pos.y][player.pos.x + 1] = 'P';
		data->map.map[player.pos.y][player.pos.x] = '0';
	}
	else if (key == 115 || key == 83)
	{
		get_player_pos(&player, data->map.map);
		data->map.map[player.pos.y + 1][player.pos.x] = 'P';
		data->map.map[player.pos.y][player.pos.x] = '0';
	}
	update_map(data->map.map_backup, data->map.map, data->map.sprites, data->mlx);
	data->map.map_backup = backup_map(data->map.map);
	return (0);
}
