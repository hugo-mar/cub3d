/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:38:33 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/16 18:05:15 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Loads an XPM file from the given path into a t_texture, storing its dimensions
and pixel data. If loading fails, it prints an error message and exits the
program gracefully.
*/
t_texture	load_texture(void *mlx_ptr, char *file_path, t_game *g)
{
	t_texture	tex;

	tex.img = mlx_xpm_file_to_image(mlx_ptr, file_path, &tex.width,
		&tex.height);
	if (!tex.img)
	{
		perror(file_path);
		clean_exit(g);
	}
	tex.addr = mlx_get_data_addr(tex.img, &tex.bits_per_pixel, &tex.line_length,
		&tex.endian);
	return (tex);
}

/*
Determines the appropriate wall texture based on the ray's side and direction,
then assigns the correct texture pointer to the provided t_tex_col structure.
*/
void	select_wall_texture(t_game *g, t_tex_col *tc)
{
	if (g->ray.side == 0)
    {
        if (g->ray.ray_dir_x > 0)
            tc->tex = &g->s_texture;
        else
            tc->tex = &g->n_texture;
    }
    else
    {
        if (g->ray.ray_dir_y > 0)
            tc->tex = &g->e_texture;
        else
            tc->tex = &g->w_texture;
    }
}
