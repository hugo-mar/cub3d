/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/10 16:51:01 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reajust_structs(t_game **game, t_mapt *maps)
{
	(*game)->map.grid = maps->int_map;
	(*game)->map.original = maps->map;
	(*game)->map.height = maps->y_max;
	(*game)->map.width = maps->x_max;
	(*game)->player.dir_x = maps->p_d[0];
	(*game)->player.dir_y = maps->p_d[1];
	(*game)->player.pos_x = maps->p_x + 1;
	(*game)->player.pos_y = maps->p_y + 1;
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

	print_game_data(game);
	//init_test_map(game);

	// maybe it's not needed (it's a good practice)
	clear_image(&game->mlx);
	
	// you can start putting pixels here, like in this example below
	render_frame(game);
		
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
	setup_hooks_and_loop(&game->mlx);
	cleanup_mlx(&game->mlx);

	ft_clean(game);

	return (0);
}
