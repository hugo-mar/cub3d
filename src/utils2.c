#include "cub3D.h"

void	mlx_cleaner(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	closeit(t_all *all, int signal)
{
	maps_cleaner(all->maps);
	mlx_cleaner(all->data);
	(void) signal;
	exit (0);
}
