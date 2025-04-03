/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/03 14:00:42 by hugo-mar         ###   ########.fr       */
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

	init_test_map(game);

	// Must go to init function
	game->ray.time = 0;
	game->ray.old_time = 0;
	
	// you can start putting pixels here, like in this example below
	clear_image(&game->mlx);
	render_frame(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);

	setup_hooks_and_loop(&game->mlx);
	cleanup_mlx(&game->mlx);

	ft_clean(game);

	return (0);
}
