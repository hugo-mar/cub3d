/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:52:32 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/03/29 12:12:47 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3d_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ESC_KEY 65307

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>	
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx_data;

void	init_mlx(t_mlx_data *mlx_data);
void	setup_hooks_and_loop(t_mlx_data *mlx_data);
void	cleanup_mlx(t_mlx_data *mlx_data);
void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
void	clear_image(t_mlx_data *data);

#endif
