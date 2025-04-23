/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:18:19 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 15:37:26 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_texture(void *mlx_ptr, t_texture *tex)
{
	if (tex && tex->img)
	{
		mlx_destroy_image(mlx_ptr, tex->img);
		tex->img = NULL;
	}
}

static void	cleanup_textures(t_game *g)
{
	destroy_texture(g->mlx.mlx, &g->n_texture);
	destroy_texture(g->mlx.mlx, &g->s_texture);
	destroy_texture(g->mlx.mlx, &g->w_texture);
	destroy_texture(g->mlx.mlx, &g->e_texture);
}

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->grid[i])
			free(map->grid[i]);
		i++;
	}
	if (map->grid)
		free(map->grid);
	map->grid = NULL;
}

void	clean_exit(t_game *g, int status)
{
	if (!g)
		exit(EXIT_FAILURE);
	cleanup_textures(g);
	free_map(&g->map);
	free_array(g->map.original);
	free(g->keys);
	g->keys = NULL;
	cleanup_mlx(&g->mlx);
	exit(status);
}
