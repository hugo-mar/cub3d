/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:52:32 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 14:38:28 by hugo-mar         ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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
    t_texture   *tex;
}   t_tex_col;



typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_map
{
	int		width;
	int		height;
	int		**grid;
	char	**original;
}			t_map;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	time;
	double	old_time;
	double	frame_time;
	double	mov_speed;
	double	rot_speed;
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
void			init_mlx(t_mlx_data *mlx_data);
void			setup_hooks_and_loop(t_mlx_data *mlx_data, t_game *game);
void			cleanup_mlx(t_mlx_data *mlx_data);
void			my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
void			clear_image(t_mlx_data *data);
unsigned int	color_rgb(int r, int g, int b);

// Initialization
t_game		*get_game(void);
void		init_data(t_game *game, t_mapt *maps);

// Cleanup
void		clean_exit(t_game *g, int status);

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
void		orientate_player(t_game *g, char direction);

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
void	init_test_map(t_game *game);
void	print_game_data(t_game *game);

//parsing extras
void	make_minimap(t_game *game);
void	fill_pixels(t_game *game, float x, float y, int color);
void	redraw_minimap(t_game *game);
void	draw_player(t_game *game);

#endif
