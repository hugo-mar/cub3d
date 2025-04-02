/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/02 17:12:08 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	t_game	*game;
	t_map	maps;
	if (parsing_start(argc, argv, &maps) == 1)
		return (1);
	readjust_structs(&game, maps);
	game = get_game();
	init_mlx(&game->mlx);

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
