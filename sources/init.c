/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:06:41 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 16:23:15 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Provides a static pointer to the single global game structure.
*/
t_game	*get_game(void)
{
	static t_game	game;

	return (&game);
}

/*
Initialises all in-game data structures: it copies the parsed map into the
engine, sets the player’s starting position, direction and camera plane,
converts ceiling/floor RGB values, and allocates the key-state array.
*/
static void	init_structures(t_game *game, t_mapt *maps)
{
	game->map.grid = maps->int_map;
	game->map.original = maps->map;
	game->map.height = maps->y_max;
	game->map.width = maps->x_max;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.pos_x = maps->p_y;
	game->player.pos_y = maps->p_x;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->ray.time = 0;
	game->ray.old_time = 0;
	game->minimap = 0;
	game->sky_color = color_rgb(maps->ceiling[0], maps->ceiling[1],
			maps->ceiling[2]);
	game->floor_color = color_rgb(maps->floor[0], maps->floor[1],
			maps->floor[2]);
	game->keys = malloc(sizeof(int) * 65536);
	if (!game->keys)
		clean_exit(game, 1);
	ft_memset(game->keys, 0, sizeof(int) * 65536);
}

static void	init_textures(t_game *game, t_mapt *maps)
{
	game->n_texture = load_texture(game->mlx.mlx, maps->no, game);
	game->s_texture = load_texture(game->mlx.mlx, maps->so, game);
	game->e_texture = load_texture(game->mlx.mlx, maps->ea, game);
	game->w_texture = load_texture(game->mlx.mlx, maps->we, game);
	free(maps->no);
	free(maps->so);
	free(maps->ea);
	free(maps->we);
}

/*
Sets up the engine by opening an MLX context, calling init_structs to populate
the game state, and then rotates the player to face the compass direction parsed
from the map.
*/
void	init_data(t_game *game, t_mapt *maps)
{
	init_mlx(&game->mlx);
	init_structures(game, maps);
	init_textures(game, maps);
	orientate_player(game, maps->p_d);
}
