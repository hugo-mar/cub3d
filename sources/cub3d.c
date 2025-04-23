/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 15:24:45 by divalent         ###   ########.fr       */
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
