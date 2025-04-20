#ifndef PARSING_H
#define PARSING_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libftprintf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_mapt
{
	char	**map;
	int		**int_map;
	float	p_y;
	float	p_x;
	float	speed;
	double	p_d[2];
	int		y_max;
	int		x_max;
	int		hitbox;
}				t_mapt;

typedef struct s_image
{
	char		*addr;
	int			bites_per_pxl;
	int			endian;
	int			height;
	int			line_len;
	int			width;
	void		*win;
	void		*img;
}				t_image;

typedef struct s_all
{
	t_mapt	*maps;
}				t_all;

int		parsing_start(int argc, char **argv, t_mapt *maps);
void	free_array(char **arr);
void	free_int_array(int **arr, int max);
void	fill(char **tab, int x, int y);
char	**copy_array(char **arr);
int		detect_zero_next_to_space(char **tab, int x, int y);
void	make_map(t_mapt *maps, char *path);
void	maps_init(t_mapt *maps);
int		check_map(t_mapt *maps, char *path);
void	form_int_map(t_mapt *maps);
int		invalid_chars(char **map);
void	maps_cleaner(t_mapt *maps);
int		closeit(t_all *all, int signal);
//void	mlx_cleaner(t_data *data);
int		on_keypress(int keysym, t_all *all);
void    make_minimap(t_all *all);
//void	fill_pixels(t_mapt *maps, t_data *data, float x, float y, int color);
int		check_hitbox(t_mapt *maps, float new_x, float new_y);

#endif