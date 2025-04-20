/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:32 by divalent          #+#    #+#             */
/*   Updated: 2025/04/10 16:47:07 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	detect_zero_next_to_space(char **tab, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (tab[y][x] && tab[y][x] == '0')
	{
		if (x > 0 && (tab[y][x - 1] == ' ' || !tab[y][x - 1] || tab[y][x - 1] == '\n'))
			return (1);
		if (tab[y][x + 1] == ' ' || !tab[y][x + 1] || tab[y][x + 1] == '\n')
			return (1);
		if (y > 0 && (tab[y - 1][x] == ' ' || !tab[y - 1][x] || tab[y - 1][x] == '\n'))
			return (1);
		if (tab[y + 1][x] == ' ' || !tab[y + 1][x] || tab[y + 1][x] == '\n')
			return (1);
	}
	return (0);
}

void	form_int_map(t_mapt *maps)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	maps->int_map = ft_calloc(maps->y_max, sizeof(int *));
	while (maps->map[y])
	{
		maps->int_map[y] = ft_calloc(maps->x_max, sizeof(int));
		while (maps->map[y][x] && maps->map[y][x] != '\n')
		{
			if (maps->map[y][x] == '0' || maps->map[y][x] == '1')
				maps->int_map[y][x] = maps->map[y][x] - 48;
			else if (maps->map[y][x] == ' ')
				maps->int_map[y][x] = 2;
			x++;
		}
		x = 0;
		y++;
	}
}

int	invalid_chars(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '\n')
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
