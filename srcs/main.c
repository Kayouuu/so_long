/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:25:36 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/13 09:40:46 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	get_width(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	get_coin_total(t_data *data)
{
	int	x;
	int	y;
	int	total;

	y = 0;
	total = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'C')
				total++;
			x++;
		}
		y++;
	}
	if (total == 0)
	{
		printf("Error\nNot enough collectibles\n");
		destroy(0, &*data);
	}
	data->total_coin = total;
}

static t_data	init(char *argv[])
{
	t_data	data;

	data.map.map_backup = NULL;
	data.map.map = parsing(argv[1]);
	check_map_error(&data);
	get_coin_total(&data);
	data.current_coin = 0;
	data.movement = 1;
	data.mlx.mlx = mlx_init();
	data.map.sprites = get_sprites(&data);
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx,
			ft_strlen(data.map.map[0]) * 63,
			get_width(data.map.map) * 63, "so_long");
	draw_map(data.mlx, data.map.sprites, data.map.map);
	data.map.map_backup = backup_map(&data);
	return (data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		printf("Error\nWrong number of arguments");
		return (-1);
	}
	data = init(argv);
	mlx_key_hook(data.mlx.mlx_win, input, &data);
	mlx_hook(data.mlx.mlx_win, 17, 1L << 0, destroy_mouse, &data);
	mlx_loop(data.mlx.mlx);
}
