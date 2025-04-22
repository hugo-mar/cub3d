/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:23:58 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/22 17:28:08 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Ends the MLX loop when the window close button is clicked
*/
static int	mouse_exit(t_mlx_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

/*
Handles key press events.
If the escape key is pressed, it stops the main loop; otherwise, it marks
the corresponding key in the game’s key state array as pressed
*/
static int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		mlx_loop_end(game->mlx.mlx);
	if (keycode == 109)
	{
		if (game->minimap == 0)
			game->minimap = 1;
		else
			game->minimap = 0;
	}
	else if (keycode >= 0 && keycode < 65536)
		game->keys[keycode] = 1;
	return (0);
}

/*
Handles key release events.
It marks the corresponding key in the game’s key state array as released.
*/
static int	key_release(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < 65536)
		game->keys[keycode] = 0;
	return (0);
}

/*
Sets up event hooks for the window (key press, key release, and window exit).
It sets up a function to render frames continuously.
In the end, it starts the main loop to process these events.
*/
void	setup_hooks_and_loop(t_mlx_data *mlx_data, t_game *game)
{
	
	mlx_hook(mlx_data->win, 2, 1L << 0, key_press, game);
	mlx_hook(mlx_data->win, 3, 1L << 1, key_release, game);
	mlx_hook(mlx_data->win, 17, 0L, mouse_exit, mlx_data);
	mlx_loop_hook(mlx_data->mlx, render_frame, game);
	mlx_loop(mlx_data->mlx);
}
