/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:25:36 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/20 13:44:33 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	sprite;

	sprite.relative_path = ft_strdup("sprites/sprite.xpm");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "so_long");
	sprite.img = mlx_xpm_file_to_image(mlx, sprite.relative_path,
			&sprite.width, &sprite.height);
	if (sprite.img)
	{
		printf("OK\n");
		mlx_put_image_to_window(mlx, mlx_win, sprite.img, 0, 0);
		mlx_loop(mlx);
	}
}
