/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/03/31 17:23:17 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	t_game	*game;

	game = get_game();

	init_mlx(&game->mlx);
	
	// maybe it's not needed (it's a good practice)
	clear_image(&game->mlx);
	
	// you can start putting pixels here, like in this example below
	for (int i = 600; i < 751; i++)
		my_mlx_pixel_put(&game->mlx, 200, i, 0x00FFFFFF); 
		
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
	setup_hooks_and_loop(&game->mlx);
	cleanup_mlx(&game->mlx);
	return (0);
}
