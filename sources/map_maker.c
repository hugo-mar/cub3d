/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:37 by divalent          #+#    #+#             */
/*   Updated: 2025/04/23 15:38:49 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	maps_init(t_mapt *maps)
{
	maps->map = NULL;
	maps->int_map = NULL;
	maps->p_d = 0;
	maps->x_max = 0;
	maps->y_max = 0;
	maps->speed = 0.333f;
	maps->ceiling[2] = -1;
	maps->floor[2] = -1;
	maps->ceiling[1] = -1;
	maps->floor[1] = -1;
	maps->ceiling[0] = -1;
	maps->floor[0] = -1;
	maps->NO = NULL;
	maps->SO = NULL;
	maps->EA = NULL;
	maps->WE = NULL;
}

void	maps_cleaner(t_mapt *maps)
{
	if (maps->map)
		free_array(maps->map);
	if (maps->int_map)
		free_int_array(maps->int_map, maps->y_max);
}

void	map_add(t_mapt *maps, int num)
{
	int		i;
	char	**temp;

	i = 0;
	temp = (char **) ft_calloc((10 * num) + 1, sizeof(char *));
	while (maps->map && maps->map[i])
	{
		temp[i] = maps->map[i];
		i++;
	}
	free(maps->map);
	maps->map = temp;
}

int	rgb_taker(t_mapt *maps, int fd)
{
	char	*line;
	//int		flag;

	//flag = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (1);
		if (ft_strncmp(line, "\n", 1) != 0)
			rgb_checkers(maps, line);
		free(line);
		if (is_all_here(maps) == 1)
			break ;
	}
	if (is_all_here(maps) == 0)
	{
		write(1, "Invalid textures/colors\n", 25);
		return (1);
	}
	return (0);
}

void	make_map(t_mapt *maps, char *path)
{
	int		fd;
	int		i;
	size_t	x;

	x = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	rgb_taker(maps, fd);
	map_add(maps, i + 1);
	maps->map[i] = get_next_line(fd);
	while (maps->map[i] != NULL)
	{
		if (x < ft_strlen(maps->map[i]))
			x = ft_strlen(maps->map[i]);
		i++;
		if (i % 10 == 0)
			map_add(maps, (i / 10) + 1);
		maps->map[i] = get_next_line(fd);
	}
	maps->y_max = i;
	maps->x_max = x - 1;
	close(fd);
}
