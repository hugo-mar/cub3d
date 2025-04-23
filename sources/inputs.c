#include "parsing.h"
#include "cub3d.h"

void	draw_player(t_game *game)
{
	fill_pixels(game, game->player.pos_y, game->player.pos_x, 0xFF0000);
}
