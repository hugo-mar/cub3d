/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:52:32 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/03/31 17:06:20 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
	void	*mlx;				// pointer to the MLX instance
	void	*win;				// pointer to the window
	void	*img;				// pointer to the image
	char	*addr;				// pointer to image pixel data
	int		bits_per_pixel;		// bits per pixel (usually 32)
	int		line_length;		// number of bytes per image line
	int		endian;				// endianness (0 = little, 1 = big)
}			t_mlx_data;

typedef struct s_player
{
	double	pos_x;				// player's position on the X axis
	double	pos_y;				// player's position on the Y axis
	double	dir_x;				// direction vector X (where the player is facing)
	double	dir_y;				// direction vector Y
	double	plane_x;			// camera plane vector X (perpendicular to dir)
	double	plane_y;			// camera plane vector Y
}			t_player;

typedef struct s_map
{
	int		width;				// number of columns in the map
	int		height;				// number of rows in the map
	int		**grid;				// 2D grid representing the map layout
}			t_map;

typedef struct s_ray
{
	double	camera_x;			// camera x-coordinate (-1 to 1)
	double	ray_dir_x;			// ray direction in x
	double	ray_dir_y;			// ray direction in y
	int		map_x;				// current cell in x
	int		map_y;				// current cell in y
	int		step_x;				// step direction in x (+1 or -1)
	int		step_y;				// step direction in y (+1 or -1)
	double	side_dist_x;		// distance to next x-side
	double	side_dist_y;		// distance to next y-side
	double	delta_dist_x;		// distance between x-sides
	double	delta_dist_y;		// distance between y-sides
	int		hit;				// did we hit a wall?
	int		side;				// was it an x-side (0) or y-side (1)?
	double	perp_wall_dist;		// perpendicular wall distance
	int		line_height;		// height of the line to draw
	int		draw_start;			// starting pixel of the wall slice
	int		draw_end;			// ending pixel of the wall slice
}			t_ray;

typedef struct s_game
{
	t_mlx_data	mlx;
	t_player	player;
	t_map		map;
	t_ray		ray;	
}				t_game;

void	init_mlx(t_mlx_data *mlx_data);
void	setup_hooks_and_loop(t_mlx_data *mlx_data);
void	cleanup_mlx(t_mlx_data *mlx_data);
void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
void	clear_image(t_mlx_data *data);

t_game	*get_game(void);

#endif
