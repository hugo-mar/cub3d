/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:43:50 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/03/29 12:12:45 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bits_per_pixel,
			&mlx_data->line_length, &mlx_data->endian);
}

static int	keyboard_exit(int keycode, t_mlx_data *data)
{
	if (keycode == ESC_KEY)
		mlx_loop_end(data->mlx);
	return (0);
}

static int	mouse_exit(t_mlx_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	setup_hooks_and_loop(t_mlx_data *mlx_data)
{
	mlx_hook(mlx_data->win, 2, 1L << 0, keyboard_exit, mlx_data);
	mlx_hook(mlx_data->win, 17, 0L, mouse_exit, mlx_data);
	mlx_loop(mlx_data->mlx);
}

void	cleanup_mlx(t_mlx_data *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx);
	free(mlx_data->mlx);
}
