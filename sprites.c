/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:21:00 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/02 15:51:16 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(char obj, t_pos pos, char **sprites, t_mlx mlx)
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
	else if (obj == 'S')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win,
			sprites[SPRITE3], pos.x, pos.y);
}

void	draw_map(t_mlx mlx, char **sprites, char **map)
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

static void	check(char **sprites)
{
	int	i;

	i = 0;
	while (sprites[i])
	{
		if (!sprites[i])
		{
			printf("Error at sprites loading");
			exit (-1);
		}
		i++;
	}
}

char	**get_sprites(void *mlx)
{
	char	**sprites;
	int		w;
	int		h;

	sprites = malloc(sizeof(void *) * (12 + 1));
	sprites[0] = mlx_xpm_file_to_image(mlx, "sprites/sprite_0.xpm", &w, &h);
	sprites[1] = mlx_xpm_file_to_image(mlx, "sprites/sprite_1.xpm", &w, &h);
	sprites[2] = mlx_xpm_file_to_image(mlx, "sprites/sprite_2.xpm", &w, &h);
	sprites[3] = mlx_xpm_file_to_image(mlx, "sprites/sprite_3.xpm", &w, &h);
	sprites[4] = mlx_xpm_file_to_image(mlx, "sprites/sprite_4.xpm", &w, &h);
	sprites[5] = mlx_xpm_file_to_image(mlx, "sprites/sprite_5.xpm", &w, &h);
	sprites[6] = mlx_xpm_file_to_image(mlx, "sprites/sprite_6.xpm", &w, &h);
	sprites[7] = mlx_xpm_file_to_image(mlx, "sprites/sprite_7.xpm", &w, &h);
	sprites[8] = mlx_xpm_file_to_image(mlx, "sprites/chest.xpm", &w, &h);
	sprites[9] = mlx_xpm_file_to_image(mlx, "sprites/grass.xpm", &w, &h);
	sprites[10] = mlx_xpm_file_to_image(mlx, "sprites/tree.xpm", &w, &h);
	sprites[11] = mlx_xpm_file_to_image(mlx, "sprites/coin.xpm", &w, &h);
	sprites[12] = NULL;
	check(sprites);
	return (sprites);
}
