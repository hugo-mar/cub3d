/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:37 by divalent          #+#    #+#             */
/*   Updated: 2025/04/01 15:27:00 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	maps_init(t_map *maps)
{
	maps->map = NULL;
	maps->int_map = NULL;
	maps->p_d[0] = 0;
	maps->p_d[1] = 0;
	maps->x_max = 0;
	maps->y_max = 0;
	maps->speed = 0.333f;
}

void	maps_cleaner(t_map *maps)
{
	if (maps->map)
		free_array(maps->map);
	if (maps->int_map)
		free_int_array(maps->int_map, maps->y_max);
}

void	map_add(t_map *maps, int num)
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

void	make_map(t_map *maps, char *path)
{
	int		fd;
	int		i;
	size_t	x;

	x = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
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
	maps->x_max = x;
	close(fd);
}
