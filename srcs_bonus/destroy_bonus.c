/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:28:44 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/10 09:40:07 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	destroy_mouse(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map)
		free_tab(data->map.map);
	if (data->map.map_backup)
		free_tab(data->map.map_backup);
	if (data->mlx.mlx)
	{
		mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	}
	while (i < 10)
	{
		mlx_destroy_image(data->mlx.mlx, data->map.sprites[i]);
		i++;
	}
	free(data->map.sprites);
	exit(1);
}

int	destroy(int key, t_data *data)
{
	int	i;

	i = 0;
	if (key != KEY_ESC)
		exit (1);
	if (data->map.map)
		free_tab(data->map.map);
	if (data->map.map_backup)
		free_tab(data->map.map_backup);
	if (data->mlx.mlx)
	{
		mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	}
	while (i < 10)
	{
		mlx_destroy_image(data->mlx.mlx, data->map.sprites[i]);
		i++;
	}
	free(data->map.sprites);
	exit(1);
}
