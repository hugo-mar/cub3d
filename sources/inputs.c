/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:16:16 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 17:38:48 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

int	check_rgb_range(t_mapt *maps)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (maps->ceiling[i] < 0 || maps->ceiling[i] > 255)
			return (1);
		if (maps->floor[i] < 0 || maps->floor[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

void	fill_player(t_game *game, float x, float y, int cell_size)
{
	int	center_size;
	int	center_start;
	int	dx;
	int	dy;

	dy = 0;
	dx = 0;
	center_size = cell_size / 3;
	center_start = (cell_size - center_size) / 2;
	while (dy < center_size)
	{
		while (dx < center_size)
		{
			my_mlx_pixel_put(&game->mlx,
				(x * cell_size) + center_start + dx,
				(y * cell_size) + center_start + dy, 0x000000);
			dx++;
		}
		dx = 0;
		dy++;
	}
}

void	fill_pixels2(t_game *game, float x, float y, int color)
{
	int	dy;
	int	dx;
	int	scale_x;
	int	scale_y;
	int	cell_size;

	scale_x = 200 / game->map.width;
	scale_y = 200 / game->map.height;
	if (scale_x < scale_y)
		cell_size = scale_x;
	else
		cell_size = scale_y;
	dy = 0;
	while (dy < cell_size)
	{
		dx = 0;
		while (dx < cell_size)
		{
			my_mlx_pixel_put(&game->mlx, (x * cell_size) + dx,
				(y * cell_size) + dy, color);
			dx++;
		}
		dy++;
	}
	fill_player(game, x, y, cell_size);
}

void	draw_player(t_game *game)
{
	fill_pixels2(game, game->player.pos_y - 0.5f + 1,
		game->player.pos_x - 0.5f, 0xFF0000);
}
