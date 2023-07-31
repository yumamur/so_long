#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	return (0);
}
