/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:00:33 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/27 18:41:47 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_input(t_data data, int key, t_obj	player)
{
	if (key == 65307)
	{
		mlx_destroy_window(data.mlx.mlx, data.mlx.mlx_win);
		exit(1);
	}
	if (key == 119 && data.map.map[player.pos.y - 1][player.pos.x] != '1')
		return (119);
	else if (key == 97 && data.map.map[player.pos.y][player.pos.x - 1] != '1')
		return (97);
	else if (key == 100 && data.map.map[player.pos.y][player.pos.x + 1] != '1')
		return (100);
	else if (key == 115 && data.map.map[player.pos.y + 1][player.pos.x] != '1')
		return (115);
	return(0);
}

static void	check_exit(t_data data, int key, t_obj	player)
{
	int	i;
	if (data.map.map_backup[player.pos.y][player.pos.x] == 'E')/* &&
			data.current_coin == data.total_coin)*/
	{
		i = 0;
		while(i < 8)
		{	
			mlx_loop_hook(data.mlx.mlx_win, anim, &data);
			mlx_loop(data.mlx.mlx);
			i++;
		}
	}
	return ;
}

int	input(int key, t_data *data)
{
	t_obj	player;
	int		asMoved;

	asMoved = 1;
	get_player_pos(&player, data->map.map);
	if (check_input(*data, key, player) == 119)
		data->map.map[player.pos.y - 1][player.pos.x] = 'P';
	else if (check_input(*data, key, player) == 97)
		data->map.map[player.pos.y][player.pos.x - 1] = 'P';
	else if (check_input(*data, key, player) == 100)
		data->map.map[player.pos.y][player.pos.x + 1] = 'P';
	else if (check_input(*data, key, player) == 115)
		data->map.map[player.pos.y + 1][player.pos.x] = 'P';
	else
		asMoved = 0;
	if (check_input(*data, key, player) != 0)
		data->map.map[player.pos.y][player.pos.x] = '0';
	get_player_pos(&player, data->map.map);
	if (data->map.map_backup[player.pos.y][player.pos.x] == 'C')
		data->current_coin++;
	if (asMoved)
	{
		printf("%d\n", data->movement++);
		check_exit(*data, key, player);
		update_map(data->map.map_backup, data->map.map, data->map.sprites, data->mlx);
		data->map.map_backup = backup_map(data->map.map);
	}
	return (0);
}
