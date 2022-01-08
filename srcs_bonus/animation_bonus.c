/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:27:29 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/08 15:26:32 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

static void	get_exit_pos(t_pos *exit, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'S')
				break ;
			x++;
		}
		if (map[y][x] == 'S')
			break ;
		y++;
	}
	exit->x = x;
	exit->y = y;
}

int	anim(int key, t_data *data)
{
	static int	i = 1;
	t_pos		exit_pos;

	if (i == 1)
		printf("Congrats !\n");
	if (key != KEY_ESC)
	{
		get_exit_pos(&exit_pos, data->map.map);
		if (i == 6)
			i = 4;
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.sprites[i], exit_pos.x * 63, exit_pos.y * 63);
		i++;
		mlx_key_hook(data->mlx.mlx_win, anim, &(*data));
		mlx_hook(data->mlx.mlx_win, 17, 1L << 0, destroy_mouse, &(*data));
		mlx_loop(data->mlx.mlx);
		return (0);
	}
	destroy(0, data);
	return (0);
}
