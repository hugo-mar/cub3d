/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:16:16 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 16:16:18 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

void	draw_player(t_game *game)
{
	fill_pixels(game, game->player.pos_y, game->player.pos_x, 0xFF0000);
}
