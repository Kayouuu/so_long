/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:54:50 by psaulnie          #+#    #+#             */
/*   Updated: 2021/12/28 12:16:11 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**trim_nl(char **parsed_map, int i)
{
	int		counter;
	char	**final_output;

	counter = 0;
	final_output = malloc(sizeof(char *) * (i + 1));
	while (counter < i)
	{
		final_output[counter] = ft_strtrim(parsed_map[counter], "\n");
		free(parsed_map[counter]);
		counter++;
	}
	final_output[counter] = NULL;
	free(parsed_map);
	return (final_output);
}

static int	file_nbr_line(char *map)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(map, O_RDONLY);
	tmp = get_next_line(fd);
	i = 1;
	free(tmp);
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		free(tmp);
		i++;
	}
	close(fd);
	return (i);
}

char	**parsing(char *map)
{
	char	**parsed_map;
	int		fd;
	int		i;
	int		counter;

	i = file_nbr_line(map);
	fd = open(map, O_RDONLY);
	parsed_map = malloc(sizeof(char *) * (i + 1));
	counter = 0;
	while (counter < i)
		parsed_map[counter++] = get_next_line(fd);
	parsed_map[counter] = NULL;
	close(fd);
	return (trim_nl(parsed_map, i));
}
