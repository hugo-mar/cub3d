/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 14:40:59 by hugo-mar         ###   ########.fr       */
/*                                                                            */a
/* ************************************************************************** */

#include "cub3d.h"

void	load_things(t_game *game, t_mapt *maps)
{
	game->keys = malloc(sizeof(int) * 65536);
	if (!game->keys)
		clean_exit(game);
	ft_memset(game->keys, 0, sizeof(game->keys));
	game->n_texture = load_texture(game->mlx.mlx, maps->NO, game);
	game->s_texture = load_texture(game->mlx.mlx, maps->SO, game);
	game->e_texture = load_texture(game->mlx.mlx, maps->EA, game);
	game->w_texture = load_texture(game->mlx.mlx, maps->WE, game);
	free(maps->NO);
	free(maps->SO);
	free(maps->EA);
	free(maps->WE);
}

void	reajust_structs(t_game **game, t_mapt *maps)
{
	(*game)->map.grid = maps->int_map;
	(*game)->map.original = maps->map;
	(*game)->map.height = maps->y_max;
	(*game)->map.width = maps->x_max;
	(*game)->player.dir_x = -1;
	(*game)->player.dir_y = 0;
	(*game)->player.pos_x = maps->p_y;
	(*game)->player.pos_y = maps->p_x;
	(*game)->player.plane_x = 0;
	(*game)->player.plane_y = 0.66;
	(*game)->ray.time = 0;
	(*game)->ray.old_time = 0;
	(*game)->sky_color = color_in_hex(maps->ceiling[0], maps->ceiling[1], maps->ceiling[2]);
	(*game)->floor_color = color_in_hex(maps->floor[0], maps->floor[1], maps->floor[2]);
	(*game)->minimap = 0;
}

int	main(int argc, char **argv)
{	
	t_game	*game;
	t_mapt	maps;

	game = get_game();
	
	// IT'S NEEDED TO PARSE THE COLORS (MUST BE 0-255)
	if (parsing_start(argc, argv, &maps) == 1)
		return (1);

	init_data(game, &maps);
	setup_hooks_and_loop(&game->mlx, game);
	clean_exit(game, 2);
	return (0);
}
