/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/22 16:36:00 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_in_hex(int r, int g, int b)
{
	int	rr = r;
	int	gg = g;
	int	bb = b;
	return ((rr << 24) | (gg << 16) | (bb << 8) | 0xFF);
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
	(*game)->keys = malloc(sizeof(int) * 65536);
	if (!(*game)->keys)
    	clean_exit(*game);
	ft_memset((*game)->keys, 0, sizeof(int) * 65536);
}

int	main(int argc, char **argv)
{	
	t_game	*game;
	t_mapt	maps;

	game = get_game();
	if (parsing_start(argc, argv, &maps) == 1)
		return (1);
	reajust_structs(&game, &maps);
	init_mlx(&game->mlx);

	//init_test_map(game);
	orientate_player(game, maps.p_d);
	temporary_init(game);
	
	setup_hooks_and_loop(&game->mlx, game);
	cleanup_mlx(&game->mlx);

	ft_clean(game);
	free(game->keys);

	return (0);
}
