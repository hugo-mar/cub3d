/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:45:48 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/03/29 12:19:40 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_mlx_data	mlx_data;

	init_mlx(&mlx_data);
	
	// maybe it's not needed (it's a good practice)
	clear_image(&mlx_data);
	
	// you can start putting pixels here, like in this example below
	for (int i = 600; i < 751; i++)
		my_mlx_pixel_put(&mlx_data, 200, i, 0x00FFFFFF); 
		
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.img, 0, 0);
	setup_hooks_and_loop(&mlx_data);
	cleanup_mlx(&mlx_data);
	return (0);
}
