/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:23:06 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/04 23:46:33 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Checks for collision by testing the grid cell in the forward direction.
If the path is clear, updates the x and y positions using the direction vector
scaled by the movement speed.
*/
void	move_forward(t_game *g)
{
	if (g->map.grid[(int)(g->player.pos_x
			+ g->player.dir_x * g->ray.mov_speed)][(int)g->player.pos_y]
			== false)
		g->player.pos_x += g->player.dir_x * g->ray.mov_speed;
	if (g->map.grid[(int)g->player.pos_x][(int)(g->player.pos_y
		+ g->player.dir_y * g->ray.mov_speed)] == false)
		g->player.pos_y += g->player.dir_y * g->ray.mov_speed;
}

/*
It verifies that the grid cells behind the player are free. If so, subtracts the
appropriate amount from the player's x and y positions based on
the direction vector and movement speed.
*/
void	move_backward(t_game *g)
{
	if (g->map.grid[(int)(g->player.pos_x
			- g->player.dir_x * g->ray.mov_speed)][(int)g->player.pos_y]
			== false)
		g->player.pos_x -= g->player.dir_x * g->ray.mov_speed;
	if (g->map.grid[(int)g->player.pos_x][(int)(g->player.pos_y
		- g->player.dir_y * g->ray.mov_speed)] == false)
		g->player.pos_y -= g->player.dir_y * g->ray.mov_speed;
}

/*
Implements a left strafe. It calculates the leftward direction (perpendicular to
the player's facing direction) and, after confirming no collision in that
direction, adjusts the player's position accordingly.
*/
void	move_left(t_game *g)
{
	if (g->map.grid[(int)(g->player.pos_x
			- g->player.dir_y * g->ray.mov_speed)][(int)g->player.pos_y]
			== false)
		g->player.pos_x -= g->player.dir_y * g->ray.mov_speed;
	if (g->map.grid[(int)g->player.pos_x][(int)(g->player.pos_y
		+ g->player.dir_x * g->ray.mov_speed)] == false)
		g->player.pos_y += g->player.dir_x * g->ray.mov_speed;
}

/*
Implements a right strafe. It computes the rightward movement (opposite of left
strafe) and moves the player if the intended position is free from obstacles.
*/
void	move_right(t_game *g)
{
	if (g->map.grid[(int)(g->player.pos_x
			+ g->player.dir_y * g->ray.mov_speed)][(int)g->player.pos_y]
			== false)
		g->player.pos_x += g->player.dir_y * g->ray.mov_speed;
	if (g->map.grid[(int)g->player.pos_x][(int)(g->player.pos_y
		- g->player.dir_x * g->ray.mov_speed)] == false)
		g->player.pos_y -= g->player.dir_x * g->ray.mov_speed;
}
