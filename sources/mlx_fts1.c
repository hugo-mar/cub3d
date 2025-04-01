/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:43:50 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/01 09:58:14 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Initializes the MLX library, creates a window and an image,
and retrieves image data pointers.
*/
void	init_mlx(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bits_per_pixel,
			&mlx_data->line_length, &mlx_data->endian);
}

/*
Ends the MLX loop if the ESC key is pressed.
*/
static int	keyboard_exit(int keycode, t_mlx_data *data)
{
	if (keycode == ESC_KEY)
		mlx_loop_end(data->mlx);
	return (0);
}

/*
Ends the MLX loop when the window close button is clicked
*/
static int	mouse_exit(t_mlx_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}


/*
Redraws the image onto the window whenever the window is exposed (needs repainting).
TO REMOVE WHEN GAME IS READY - Useful only for static images in small windows.
*/
static int	expose_hook(t_mlx_data *data)
{
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

/*
Registers the keyboard and mouse hooks, then starts the MLX event loop.
*/
void	setup_hooks_and_loop(t_mlx_data *mlx_data)
{
	// TO REMOVE
	mlx_hook(mlx_data->win, 12, 1L << 15, expose_hook, mlx_data);
	
	mlx_hook(mlx_data->win, 2, 1L << 0, keyboard_exit, mlx_data);
	mlx_hook(mlx_data->win, 17, 0L, mouse_exit, mlx_data);
	mlx_loop(mlx_data->mlx);
}

/*
Destroys the image, window, and MLX instance to free resources.
*/
void	cleanup_mlx(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx);
	free(mlx_data->mlx);
}
