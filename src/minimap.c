#include "cub3D.h"

void	fill_pixels(t_map *maps, t_data *data, float x, float y, int color)
{
	int	dy;
	int	dx;
	int	scale_x;
	int scale_y;
	int	cell_size;

	scale_x = 200 / maps->x_max;
    scale_y = 200 / maps->y_max;
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
			mlx_pixel_put(data->mlx, data->mlx_win, (x * cell_size) + dx, (y * cell_size) + dy, color);
			dx++;
		}
		dx = 0;
		dy++;
	}
}

void	fill_minimap(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (all->maps->map[y])
	{
		while (all->maps->map[y][x])
		{
			if (all->maps->map[y][x] == '1')
				fill_pixels(all->maps, all->data, x, y, 0x0000FF);
			x++;
		}
		x = 0;
		y++;
	}
	fill_pixels(all->maps, all->data, all->maps->p_x, all->maps->p_y, 0xFF0000);
}

void	make_minimap(t_all *all)
{
	t_image	img;
	int		img_width;
	int		img_height;

	img.addr = "./assets/minimap.xpm";
	img.img = mlx_xpm_file_to_image(all->data->mlx, img.addr,
			&img_width, &img_height);
	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win, img.img,
		0, 0);
	mlx_destroy_image(all->data->mlx, img.img);
	fill_minimap(all);
	
}
