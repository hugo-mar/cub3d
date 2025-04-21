/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:26 by divalent          #+#    #+#             */
/*   Updated: 2025/04/21 18:34:10 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	player_where(t_mapt *maps, int x, int y)
{
	maps->p_x = x;
	maps->p_y = y;
	maps->p_d = maps->map[y][x];
	maps->map[y][x] = '0';
}

int	has_player(t_mapt *maps)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (maps->map[y])
	{
		while (maps->map[y][x])
		{
			if (maps->map[y][x] == 'N' || maps->map[y][x] == 'W' ||
				maps->map[y][x] == 'E' || maps->map[y][x] == 'S')
			{
				if (maps->p_d != 0)
					return (1);
				player_where(maps, x, y);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (maps->p_d == 0)
		return (1);
	return (0);
}

int	is_closed(char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (detect_zero_next_to_space(map, x, y) == 1)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	sep_map(char **map)
{
	int	k;

	k = 0;
	while (map[k][0] && map[k][0] == '\n')
		k++;
	while (map[k] && map[k][0] && map[k][0] != '\n')
		k++;
	while (map[k] && map[k][0] && map[k][0] == '\n')
		k++;
	if (map[k] == NULL || map[k][0] == '\0')
		return (0);
	return (1);
}

int	check_map(t_mapt *maps, char *path)
{
	int		i;

	i = 0;
	if (!path)
		return (1);
	while (path[i] && path[i] != '.')
		i++;
	if (ft_strncmp(path + i, ".cub", 5))
		return (1);
	make_map(maps, path);
	if (has_player(maps) == 1)
		return (1);
	if (invalid_chars(maps->map) == 1)
		return (1);
	if (sep_map(maps->map) == 1)
		return (1);
	if (is_closed(maps->map) == 1)
		return (1);
	form_int_map(maps);
	return (0);
}
