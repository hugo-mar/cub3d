/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:29 by divalent          #+#    #+#             */
/*   Updated: 2025/03/27 16:42:57 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	cub(t_map *maps)
{
	t_data	data;
	t_all	all;

	all.data = &data;
	all.maps = maps;
	data.mlx = mlx_init();
	if (!data.mlx)
		return ;
	data.mlx_win = mlx_new_window(data.mlx, (maps->x_max * 64),
			(maps->y_max * 64), "cub3D");
	if (!data.mlx_win)
		return (free(data.mlx_win));
	make_minimap(&all);
	mlx_hook(data.mlx_win, 17, 0, &closeit, &all);
	mlx_key_hook(data.mlx_win, &on_keypress, &all);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	t_map maps;

	if (argc < 2 || argc > 2)
		return (1);
	maps_init(&maps);
	if (check_map(&maps, argv[1]) == 1)
	{
		ft_printf("Error\n Invalid Map (for some reason)\n");
		maps_cleaner(&maps);
		return (1);
	}
	cub(&maps);
}
