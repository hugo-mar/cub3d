/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 23:21:23 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 16:12:30 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Rotates the player's view to the left by applying a rotation matrix to both the
player's direction vector and the camera plane.
*/
void	rotate_left(t_game *g)
{
	g->ray.old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(g->ray.rot_speed)
		- g->player.dir_y * sin(g->ray.rot_speed);
	g->player.dir_y = g->ray.old_dir_x * sin(g->ray.rot_speed)
		+ g->player.dir_y * cos(g->ray.rot_speed);
	g->ray.old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(g->ray.rot_speed)
		- g->player.plane_y * sin(g->ray.rot_speed);
	g->player.plane_y = g->ray.old_plane_x * sin(g->ray.rot_speed)
		+ g->player.plane_y * cos(g->ray.rot_speed);
}

/*
Rotates the player's view to the right using a similar approach as rotate_left,
but with a negative rotation speed to achieve the opposite direction.
*/
void	rotate_right(t_game *g)
{
	g->ray.old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(-g->ray.rot_speed)
		- g->player.dir_y * sin(-g->ray.rot_speed);
	g->player.dir_y = g->ray.old_dir_x * sin(-g->ray.rot_speed)
		+ g->player.dir_y * cos(-g->ray.rot_speed);
	g->ray.old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(-g->ray.rot_speed)
		- g->player.plane_y * sin(-g->ray.rot_speed);
	g->player.plane_y = g->ray.old_plane_x * sin(-g->ray.rot_speed)
		+ g->player.plane_y * cos(-g->ray.rot_speed);
}

/*
Reorients the player from its default north‑facing direction by assigning the
required rotation angle (in radians).
*/
void	orientate_player(t_game *g, char direction)
{
	if (direction == 'N')
		return ;
	else if (direction == 'S')
		g->ray.rot_speed = PI;
	else if (direction == 'E')
		g->ray.rot_speed = 3 * PI / 2;
	else if (direction == 'W')
		g->ray.rot_speed = PI / 2;
	else
		return ;
	rotate_left(g);
}

/*
Returns the current time in milliseconds by using the gettimeofday function.
This is useful for calculating frame timing and synchronizing movements.
*/
double	get_time_in_milliseconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0));
}

/*
Updates the game's timing by computing the frame duration and adjusting movement
and rotation speeds accordingly. It then checks which movement keys (W, A, S, D,
left arrow, right arrow) are pressed and calls the corresponding function.
*/
void	process_player_movement(t_game *game)
{
	game->ray.old_time = game->ray.time;
	game->ray.time = get_time_in_milliseconds();
	game->ray.frame_time = (game->ray.time - game->ray.old_time) / 1000.0;
	game->ray.mov_speed = game->ray.frame_time * 5.0;
	game->ray.rot_speed = game->ray.frame_time * 3.0;
	if (game->keys[W_KEY])
		move_forward(game);
	if (game->keys[S_KEY])
		move_backward(game);
	if (game->keys[A_KEY])
		move_left(game);
	if (game->keys[D_KEY])
		move_right(game);
	if (game->keys[LEFT_KEY])
		rotate_left(game);
	if (game->keys[RIGHT_KEY])
		rotate_right(game);
}
