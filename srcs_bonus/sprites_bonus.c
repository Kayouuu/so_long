/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:21:00 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/10 09:48:41 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	draw(char obj, t_pos pos, void **sprites, t_mlx mlx)
{
	if (obj == 'P')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win,
			sprites[SPRITE0], pos.x, pos.y);
	else if (obj == '0')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win,
			sprites[GRASS], pos.x, pos.y);
	else if (obj == '1')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win,
			sprites[TREE], pos.x, pos.y);
	else if (obj == 'E')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win,
			sprites[CHEST], pos.x, pos.y);
	else if (obj == 'C')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win,
			sprites[COIN], pos.x, pos.y);
	else if (obj == 'A')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win,
			sprites[ENEMY], pos.x, pos.y);
	else if (obj == 'B')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win,
			sprites[ENEMY1], pos.x, pos.y);
	else if (obj == 'S')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win,
			sprites[SPRITE0], pos.x, pos.y);
}

void	draw_map(t_mlx mlx, void **sprites, char **map)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	pos.y = 0;
	while (map[i])
	{
		j = 0;
		pos.x = 0;
		while (map[i][j])
		{
			draw(map[i][j], pos, sprites, mlx);
			j++;
			pos.x += 63;
		}
		i++;
		pos.y += 63;
	}
}

static void	check(void **sprites, t_data *data)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (sprites[i] == NULL)
		{
			printf("Error at sprites loading");
			i = 0;
			while (sprites[i] != NULL)
			{
				mlx_destroy_image(data->mlx.mlx, sprites[i]);
				i++;
			}
			exit (-1);
		}
		i++;
	}
}

void	**get_sprites(t_data *data)
{
	void	**s;
	int		w;
	int		i;

	s = malloc(sizeof(void *) * (12 + 1));
	if (!s)
		destroy(0, &*data);
	i = 0;
	while (i++ < 11)
		s[i] = NULL;
	s[0] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/p0.xpm", &w, &w);
	s[1] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/p1.xpm", &w, &w);
	s[2] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/p2.xpm", &w, &w);
	s[3] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/p3.xpm", &w, &w);
	s[4] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/p4.xpm", &w, &w);
	s[5] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/p5.xpm", &w, &w);
	s[6] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/chest.xpm", &w, &w);
	s[7] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/grass.xpm", &w, &w);
	s[8] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/tree.xpm", &w, &w);
	s[9] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/coin.xpm", &w, &w);
	s[10] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/enemy.xpm", &w, &w);
	s[11] = mlx_xpm_file_to_image(data->mlx.mlx, "sprites/enemy1.xpm", &w, &w);
	s[12] = NULL;
	check(s, &*data);
	return (s);
}
