/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:25:36 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/05 09:35:34 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_width(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	get_enemy_total(char **map)
{
	int	x;
	int	y;
	int	total;

	y = 0;
	total = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'A')
				total++;
			x++;
		}
		y++;
	}
	return (total);
}

static int	get_coin_total(char **map)
{
	int	x;
	int	y;
	int	total;

	y = 0;
	total = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				total++;
			x++;
		}
		y++;
	}
	if (total == 0)
	{
		printf("Map error");
		exit(-1);
	}
	return (total);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		printf("Wrong number of arguments");
		return (-1);
	}
	data.map.map = parsing(argv[1]);
	check_map_error(data.map.map);
	data.current_coin = 0;
	data.total_coin = get_coin_total(data.map.map);
	data.enemy_nbr = get_enemy_total(data.map.map);
	data.enemy_pos = NULL;
	data.movement = 1;
	data.mlx.mlx = mlx_init();
	data.map.sprites = get_sprites(data.mlx.mlx);
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx,
			ft_strlen(data.map.map[0]) * 63,
			get_width(data.map.map) * 63, "so_long");
	draw_map(data.mlx, data.map.sprites, data.map.map);
	data.map.map_backup = backup_map(data.map.map);
	mlx_key_hook(data.mlx.mlx_win, input, &data);
	mlx_hook(data.mlx.mlx_win, 17, 1L << 0, destroy_mouse, &data);
	mlx_loop_hook(data.mlx.mlx_win, enemy, &data);
	mlx_loop(data.mlx.mlx);
}
