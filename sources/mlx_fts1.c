/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:43:50 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/04 22:53:23 by hugo-mar         ###   ########.fr       */
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
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT,
			"cub3d");
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bits_per_pixel,
			&mlx_data->line_length, &mlx_data->endian);
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

/*
Places a pixel of the specified color at the given coordinates in the image.
*/
void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
Fills the entire image area with a black (zero) background.
*/
void	clear_image(t_mlx_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}
