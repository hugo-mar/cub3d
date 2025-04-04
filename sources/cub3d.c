/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/05 00:02:46 by hugo-mar         ###   ########.fr       */
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
	game->keys = malloc(sizeof(int) * 65536);
	if (!game->keys)
    exit(1);
	ft_memset(game->keys, 0, sizeof(game->keys));
	
	setup_hooks_and_loop(&game->mlx, game);
	cleanup_mlx(&game->mlx);

	ft_clean(game);
	free(game->keys);

	return (0);
}
