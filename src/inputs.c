#include "cub3D.h"

void	draw_player(t_data *data, t_map *maps)
{
	fill_pixels(maps, data, maps->p_x, maps->p_y, 0xFF0000);
}

void	redraw_minimap(t_map *maps, t_data *data)
{
	fill_pixels(maps, data, maps->p_x, maps->p_y, 0xcccccc);
}

void	move_player(t_map *maps, t_data *data, float delta_time, int direction_x, int direction_y)
{
	float	new_x;
	float	new_y;

	new_x = maps->p_x + direction_x * maps->speed * delta_time;
	new_y = maps->p_y + direction_y * maps->speed * delta_time;
	redraw_minimap(maps, data);
	maps->p_x = new_x;
	maps->p_y = new_y;
	draw_player(data, maps);
}

void	relocate_player(t_map *maps, t_data *data, int keysym)
{
	int	direction_x;
	int	direction_y;

	if (keysym == 119)
	{
		direction_x = maps->p_d[0];
		direction_y = maps->p_d[1];
		move_player(maps, data,  1.0, direction_x, direction_y);
	}
	else if (keysym == 115)
	{
		direction_x = -maps->p_d[0];
		direction_y = -maps->p_d[1];
		move_player(maps, data, 1.0, direction_x, direction_y);
	}
	else if (keysym == 100)
	{
		direction_x = maps->p_d[0] + 1;
		direction_y = maps->p_d[1] + 1;
		move_player(maps, data, 1.0, direction_x, direction_y);
	}
	else if (keysym == 97)
	{
		direction_x = -maps->p_d[0] - 1;
		direction_y = -maps->p_d[1] - 1;
		move_player(maps, data, 1.0, direction_x, direction_y);
	}
}

int	on_keypress(int keysym, t_all *all)
{
	if (keysym == 65307)
		closeit(all, 0);
	if (keysym == 100 || keysym == 97 || keysym == 115 || keysym == 119)
		relocate_player(all->maps, all->data, keysym);
	return (0);
}
