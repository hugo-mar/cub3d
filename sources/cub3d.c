/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/20 17:05:51 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reajust_structs(t_game **game, t_mapt *maps)
{
	(*game)->map.grid = maps->int_map;
	(*game)->map.original = maps->map;
	(*game)->map.height = maps->y_max;
	(*game)->map.width = maps->x_max;
	(*game)->player.dir_x = -1;
	(*game)->player.dir_y = 0;
	(*game)->player.pos_x = maps->p_y + 1;
	(*game)->player.pos_y = maps->p_x + 1;
	(*game)->player.plane_x = 0;
	(*game)->player.plane_y = 0.66;
	(*game)->ray.time = 0;
	(*game)->ray.old_time = 0;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	t_game	*game;
	t_mapt	maps;
	game = get_game();
	if (parsing_start(argc, argv, &maps) == 1)
		return (1);
	reajust_structs(&game, &maps);
	init_mlx(&game->mlx);

	//init_test_map(game);
	temporary_init(game);
	
	setup_hooks_and_loop(&game->mlx, game);
	cleanup_mlx(&game->mlx);

	ft_clean(game);
	free(game->keys);

	return (0);
}
