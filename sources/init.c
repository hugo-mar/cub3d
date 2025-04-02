/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:06:41 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/01 22:24:16 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Provides a static pointer to the single global game structure.
*/
t_game *get_game(void)
{
	static	t_game game;

	return(&game);
}

// We need to init time and old_time