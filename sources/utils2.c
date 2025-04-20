#include "cub3d.h"

void	mlx_cleaner(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	closeit(t_all *all, int signal)
{
	maps_cleaner(all->maps);
	//mlx_cleaner(all->data);
	(void) signal;
	exit (0);
}
