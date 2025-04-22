/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:52:32 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/22 16:03:01 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TEXTURED_RAYCASTER 1
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define PI 3.141592653589793

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>	
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "parsing.h"
# include <sys/time.h>

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

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_texture;

typedef struct s_tex_col
{
    double      wall_x;
    int         tex_x;
    double      step;
    double      tex_pos;
    int         tex_y;
    unsigned int color;
    t_texture   *tex;			// ponteiro para a textura actual
}   t_tex_col;



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
	char	**original;
}			t_map;

typedef struct s_ray
{
	double	camera_x;			// camera x-coordinate (-1 to 1) (x-coordinate on the camera plane that the current x-coordinate of the screen represents)
	double	ray_dir_x;			// ray direction in x
	double	ray_dir_y;			// ray direction in y
	int		map_x;				// current cell in x (current square of the map the ray is in)
	int		map_y;				// current cell in y (current square of the map the ray is in)
	int		step_x;				// step direction in x (+1 or -1)
	int		step_y;				// step direction in y (+1 or -1)
	double	side_dist_x;		// distance to next x-side
	double	side_dist_y;		// distance to next y-side
	double	delta_dist_x;		// distance the ray has to travel between x-sides
	double	delta_dist_y;		// distance the ray has to travel between y-sides
	int		hit;				// did we hit a wall?
	int		side;				// was it an x-side (0) or y-side (1)?
	double	perp_wall_dist;		// perpendicular wall distance
	int		line_height;		// height of the line to draw
	int		draw_start;			// starting pixel of the wall slice
	int		draw_end;			// ending pixel of the wall slice
	double	time;				// time of current frame
	double	old_time;			// time of previous frame
	double	frame_time;			// time the current frame has taken to render
	double	mov_speed;			// movement speed
	double	rot_speed;			// rotation speed
	double	old_dir_x;
	double	old_plane_x;
}			t_ray;

typedef struct s_game
{
	t_mlx_data	mlx;
	t_player	player;
	t_map		map;
	t_ray		ray;
	int			*keys;
	t_texture	tex;
	t_texture	n_texture;
	t_texture	s_texture;
	t_texture	w_texture;
	t_texture	e_texture;
	int			sky_color;
	int			floor_color;
}				t_game;

// Minilibx
void		init_mlx(t_mlx_data *mlx_data);
void		setup_hooks_and_loop(t_mlx_data *mlx_data, t_game *game);
void		cleanup_mlx(t_mlx_data *mlx_data);
void		my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
void		clear_image(t_mlx_data *data);

// Initialization
t_game		*get_game(void);
void		orientate_player(t_game *g, char direction);


// Cleanup
void		clean_exit(t_game *g);

// Raycasting
int			render_frame(t_game *game);
double		get_delta_dist(double ray_dir);
void		draw_vertical_line(t_game *g, int x);
void		draw_floor_and_sky(t_game *game, int x);


// Movement
void		process_player_movement(t_game *game);
double		get_time_in_milliseconds(void);
void		move_forward(t_game *g);
void		move_backward(t_game *g);
void		move_left(t_game *g);
void		move_right(t_game *g);
void		rotate_left(t_game *g);
void		rotate_right(t_game *g);

// Textures
t_texture	load_texture(void *mlx_ptr, char *file_path, t_game *g);
void		select_wall_texture(t_game *g, t_tex_col *tc);
double		compute_wall_x(t_game *g);
int			compute_texture_x(double wall_x, t_texture *tex, t_game *g);
void		compute_texture_mapping_params(t_game *g, t_tex_col *tc);
void		render_texture_column_pixels(t_game *g, t_tex_col *tc, int x);
void		draw_textured_column(t_game *g, int x);

// Temporary functions (remove when obsolete)
void		ft_clean(t_game *game);
void		init_test_map(t_game *game);
void		temporary_init(t_game *game);
void		print_game_data(t_game *game);
void		*ft_memset(void *s, int c, size_t n);

// Temporary functions (remove when obsolete)
void	ft_clean(t_game *game);
void	init_test_map(t_game *game);
void	print_game_data(t_game *game);

//parsing extras
void	make_minimap(t_game *game);
void	fill_pixels(t_game *game, float x, float y, int color);
void	redraw_minimap(t_game *game);
void	draw_player(t_game *game);

#endif
