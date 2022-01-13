/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:54:50 by psaulnie          #+#    #+#             */
/*   Updated: 2022/01/13 09:42:03 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	end_program(char *str)
{
	printf("Error\n%s\n", str);
	exit(-1);
}

static void	check_map_format(char *map)
{
	int	is_valid;
	int	i;

	is_valid = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strncmp(&map[i], ".ber", 4) == 0)
		{
			is_valid = 1;
			break ;
		}
		i++;
	}
	if (is_valid)
		return ;
	printf("Error\nWrong file format\n");
	exit(-1);
}

static char	**trim_nl(char **parsed_map, int i)
{
	int		counter;
	char	**final_output;

	counter = 0;
	final_output = malloc(sizeof(char *) * (i + 1));
	if (!final_output)
	{
		printf("Error\nMalloc error\n");
		free_tab(parsed_map);
		exit (-1);
	}
	while (counter < i)
	{
		final_output[counter] = ft_strtrim(parsed_map[counter], "\n");
		if (!final_output)
		{
			printf("Error\nMalloc error\n");
			free_tab(final_output);
			exit (-1);
		}
		free(parsed_map[counter++]);
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

	check_map_format(map);
	i = file_nbr_line(map);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		end_program("File not found");
	parsed_map = malloc(sizeof(char *) * (i + 1));
	if (!parsed_map)
	{
		close(fd);
		end_program("Malloc error");
	}
	counter = 0;
	while (counter < i)
		parsed_map[counter++] = get_next_line(fd);
	parsed_map[counter] = NULL;
	close(fd);
	return (trim_nl(parsed_map, i));
}
