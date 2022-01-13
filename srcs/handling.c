/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:21:10 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/13 09:40:25 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check(int condition_if, t_data *data)
{
	if (condition_if)
	{
		printf("Error\nMap not closed\n");
		destroy(0, &*data);
	}
}

static void	check_other_char(t_data *data)
{
	t_pos	pos;
	char	c;

	pos.y = 0;
	while (data->map.map[pos.y])
	{
		pos.x = 0;
		while (data->map.map[pos.y][pos.x])
		{
			c = data->map.map[pos.y][pos.x];
			if (c != 'P' && c != '0' && c != '1' && c != 'E' && c != 'C')
			{
				printf("Error\nCharacter %c not handled\n", c);
				destroy(0, &*data);
			}
			pos.x++;
		}
		pos.y++;
	}
}

static void	check_walls(t_data *data, int last_line)
{
	t_pos	pos;

	pos.x = 0;
	while (data->map.map[0][pos.x])
		check(data->map.map[0][pos.x++] != '1', &*data);
	pos.y = 0;
	while (pos.y < last_line && data->map.map[pos.y][0])
		check(data->map.map[pos.y++][0] != '1', &*data);
	pos.y = 0;
	while (pos.y < last_line && data->map.map[pos.y][pos.x - 1])
		check(data->map.map[pos.y++][pos.x - 1] != '1', &*data);
	pos.x = 0;
	while (data->map.map[pos.y][pos.x])
		check(data->map.map[pos.y][pos.x++] != '1', &*data);
	check_other_char(&*data);
}

void	check_map_error(t_data *data)
{
	int		x_len;
	int		player_nbr;
	t_pos	pos;

	x_len = 0;
	player_nbr = 0;
	pos.y = 0;
	while (data->map.map[0][x_len])
		x_len++;
	while (data->map.map[++pos.y])
	{
		pos.x = 0;
		while (data->map.map[pos.y][pos.x])
			if (data->map.map[pos.y][pos.x++] == 'P')
				player_nbr++;
		if (pos.x != x_len)
			break ;
	}
	if (player_nbr != 1)
		printf("Error\nWrong number of player\n");
	else if (pos.x != x_len)
		printf("Error\nNon equal length\n");
	if (player_nbr != 1 || pos.x != x_len)
		destroy(0, &*data);
	check_walls(&*data, pos.y - 1);
}
