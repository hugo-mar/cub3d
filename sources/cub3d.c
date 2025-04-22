/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 00:01:38 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	color_rgb(int r, int g, int b)
{
	return (r << 16) | (g << 8) | b;
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
	(*game)->sky_color = color_rgb(maps->ceiling[0], maps->ceiling[1],
		maps->ceiling[2]);
	(*game)->floor_color = color_rgb(maps->floor[0], maps->floor[1],
		maps->floor[2]);
	(*game)->keys = malloc(sizeof(int) * 65536);
	if (!(*game)->keys)
    	clean_exit(*game, 1);
	ft_memset((*game)->keys, 0, sizeof(int) * 65536);
}

int	main(int argc, char **argv)
{	
	t_game	*game;
	t_mapt	maps;

	game = get_game();
	if (parsing_start(argc, argv, &maps) == 1)
		return (1);

	// THIS COULD GO TO A FUNCTION INIT_STRUCTURES
	reajust_structs(&game, &maps);
	orientate_player(game, maps.p_d);
	init_mlx(&game->mlx);
	
	// CAN DISAPEAR WHEN TEXTURES LOADED FROM FILE
	temporary_init(game);
	
	setup_hooks_and_loop(&game->mlx, game);

	clean_exit(game, 1);
	return (0);
}
