/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:25:36 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/21 16:29:47 by psaulnie         ###   ########.fr       */
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
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_img	sprite;

	if (argc != 2)
	{
		printf("Wrong number of arguments");
		return (-1);
	}
	map = parsing(argv[1]);
	sprite.relative_path = ft_strdup("sprites/sprite_00.xpm");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, ft_strlen(map[0]) * 64,
			get_width(map) * 64, "so_long");
	sprite.img = mlx_xpm_file_to_image(mlx, sprite.relative_path,
			&sprite.size.width, &sprite.size.height);
	if (!sprite.img)
	{
		printf("Error at image loading");
		return (-1);
	}
	mlx_put_image_to_window(mlx, mlx_win, sprite.img, 0, 0);
	mlx_loop(mlx);
}
