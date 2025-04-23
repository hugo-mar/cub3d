/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 14:40:59 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
