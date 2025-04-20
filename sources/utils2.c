#include "cub3d.h"

int		checka_isto(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
		i++;
	if (i < 3)
		return (1);
	return (0);
}

void	rgb_2(t_mapt *map, char *line)
{
	char	**temp;

	temp = NULL;
	if (ft_strncmp(line, "C", 1) == 0)
	{
		temp = ft_split(line + 2, ',');
		if (checka_isto(temp) == 1)
			return ;
		map->ceiling[0] = ft_atoi(temp[0]);
		map->ceiling[1] = ft_atoi(temp[1]);
		map->ceiling[2] = ft_atoi(temp[2]);
		return ;
	}
	else if (ft_strncmp(line, "F", 1) == 0)
	{
		temp = ft_split(line + 2, ',');
		if (checka_isto(temp) == 1)
			return ;
		map->floor[0] = ft_atoi(temp[0]);
		map->floor[1] = ft_atoi(temp[1]);
		map->floor[2] = ft_atoi(temp[2]);
		return ;
	}
}

void	rgb_checkers(t_mapt *map, char *line)
{
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		map->NO = line + 3;
		return ;
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		map->SO = line + 3;
		return ;
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		map->WE = line + 3;
		return ;
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		map->EA = line + 3;
		return ;
	}
	else
		rgb_2(map, line);
}

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
