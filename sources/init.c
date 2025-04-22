/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:06:41 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/22 17:12:27 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Provides a static pointer to the single global game structure.
*/
t_game	*get_game(void)
{
	static t_game	game;

	return (&game);
}

// We need to init time and old_time


void	clean_exit(t_game *g)
{
	// IT NEEDS TO BE MORE ROBUST AND EFFICIENT
	ft_clean(g);
	free(g->keys);
	cleanup_mlx(&g->mlx);
	exit(EXIT_FAILURE);
}
