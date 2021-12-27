/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:55:12 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/27 18:40:20 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	anim(t_data *data)
{
	t_obj		player;
	static int 	i;

	i = 0;
	printf("{%d}\n", i);
	get_player_pos(&player, data->map.map);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->map.sprites[i], player.pos.x * 63, player.pos.y * 63);
	i++;
}
