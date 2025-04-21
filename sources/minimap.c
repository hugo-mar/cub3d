#include "parsing.h"
#include "cub3d.h"

void	fill_pixels(t_game *game, float x, float y, int color)
{
	int	dy;
	int	dx;
	int	scale_x;
	int scale_y;
	int	cell_size;

	scale_x = 200 / game->map.width;
    scale_y = 200 / game->map.height;
	if (scale_x < scale_y)
		cell_size = scale_x;
	else
		cell_size = scale_y;
	dx = 0;
	dy = 0;
	while (dy < cell_size)
	{
		while (dx < cell_size)
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.win, (x * cell_size) + dx, (y * cell_size) + dy, color);
			dx++;
		}
		dx = 0;
		dy++;
	}
}

void	fill_minimap(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.original[y])
	{
		while (game->map.original[y][x])
		{
			if (game->map.original[y][x] == '1')
				fill_pixels(game, x, y, 0x0000FF);
			x++;
		}
		x = 0;
		y++;
	}
	fill_pixels(game, game->player.pos_y, game->player.pos_x, 0xFF0000);
}

void	make_minimap(t_game *game)
{
	t_image	img;
	int		img_width;
	int		img_height;

	img.addr = "./textures/minimap.xpm";
	img.img = mlx_xpm_file_to_image(game->mlx.mlx, img.addr,
			&img_width, &img_height);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, img.img,
		0, 0);
	mlx_destroy_image(game->mlx.mlx, img.img);
	fill_minimap(game);
}
