/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:37:58 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/16 19:14:19 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int world_map[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	ft_clean(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		if (game->map.grid[i])
			free(game->map.grid[i]);
		i++;
	}
	if (game->map.grid)
		free(game->map.grid);
}

void	init_test_map(t_game *game)
{
	game->map.height = 24;
	game->map.width = 24;
	game->map.grid = (int **)malloc(sizeof(int *) * game->map.height);
	if (!game->map.grid)
		exit(1);
	for (int i = 0; i < game->map.height; i++)
	{
		game->map.grid[i] = (int *)malloc(sizeof(int) * game->map.width);
			if (!game->map.grid[i])
			{
				ft_clean(game);
				exit(1);
			}
	}
	for (int i = 0; i < game->map.height; i++)
		for (int j = 0; j < game->map.width; j++)
			game->map.grid[i][j] = world_map[i][j];
	game->player.pos_x = 22;
	game->player.pos_y = 12;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->ray.time = 0;
	game->ray.old_time = 0;

	orientate_player(game, 'W');
}

void	print_game_data(t_game *game)
{
	printf("GAME DATA\n");
	printf("- window size: %dx%d\n", WIN_WIDTH, WIN_HEIGHT);
	printf("- map size: %dx%d\n", game->map.width, game->map.height);
	printf("- posX: %f, posY: %f\n", game->player.pos_x, game->player.pos_y);
	printf("- dirX: %f, dirY: %f\n", game->player.dir_x, game->player.dir_y);
	printf("- planeX: %f, planeY: %f\n", game->player.plane_x, game->player.plane_y);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}

void	temporary_init(t_game *game)
{
	game->ray.time = 0;
	game->ray.old_time = 0;
	game->keys = malloc(sizeof(int) * 65536);
	if (!game->keys)
    	clean_exit(game);
	ft_memset(game->keys, 0, sizeof(game->keys));
	game->n_texture = load_texture(game->mlx.mlx, "textures/wall1.xpm", game);
	game->s_texture = load_texture(game->mlx.mlx, "textures/wall2.xpm", game);
	game->e_texture = load_texture(game->mlx.mlx, "textures/wall3.xpm", game);
	game->w_texture = load_texture(game->mlx.mlx, "textures/wall4.xpm", game);
}

/*
Ends the MLX loop if the ESC key is pressed.
*/
// static int	keyboard_exit(int keycode, t_mlx_data *data)
// {
// 	if (keycode == ESC_KEY)
// 		mlx_loop_end(data->mlx);
// 	return (0);
// }

/*
Redraws the image onto the window whenever the window is exposed (needs repainting).
*/
// static int	expose_hook(t_mlx_data *data)
// {
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//     return (0);
// }