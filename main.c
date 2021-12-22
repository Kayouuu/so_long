/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:25:36 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/22 17:28:15 by psaulnie         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	char	**map;
	char	**sprites;
	t_mlx	mlx;

	if (argc != 2)
	{
		printf("Wrong number of arguments");
		return (-1);
	}
	map = parsing(argv[1]);
	mlx.mlx = mlx_init();
	sprites = get_sprites(mlx.mlx);
	mlx.mlx_win = mlx_new_window(mlx.mlx, ft_strlen(map[0]) * 63,
			get_width(map) * 63, "so_long");
	draw_map(mlx, sprites, map);
	mlx_loop(mlx.mlx);
}
