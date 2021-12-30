/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:21:10 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/30 12:00:20 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(char **map, int last_line)
{
	int	x;
	int	y;
	
	x = 0;
	while(map[0][x])
	{
		if (map[0][x] != '1')
		{
			printf("Map error");
			exit(-1);
		}
		x++;
	}
	y = 0;
	while (y < last_line && map[y][0])
	{
		if (map[y][0] != '1')
		{
			printf("Map error");
			exit(-1);
		}
		y++;
	}
	y = 0;
	while (y < last_line && map[y][x - 1])
	{
		if (map[y][x - 1] != '1')
		{
			printf("Map error");
			exit(-1);
		}
		y++;
	}
	x = 0;
	while (map[y][x])
	{
		if (map[y][x] != '1')
		{
			printf("Map error");
			exit(-1);
		}
		x++;
	}
}

void	check_map_error(char **map)
{
	int	x_len;
	int	player_nbr;
	int	x;
	int	y;

	x_len = 0;
	player_nbr = 0;
	y = 0;
	while (map[0][x_len])
		x_len++;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				player_nbr++;
			x++;
		}
		if (x != x_len)
			break ;
		y++;
	}
	if (player_nbr != 1 || x != x_len)
	{
		printf("Map error");
		exit (-1);
	}
	check_walls(map, y - 1);
}
