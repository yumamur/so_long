#include "so_long.h"
#include <mlx.h>

void	exit_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	mlx_destroy_image(game->mlx, game->img_lst.ptr);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}
