#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	map_init(game, argv[1]);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "game");
	mlx_hook(game->win, 2, 1L << 0, handle_key_events, 0);
	mlx_loop(game->mlx);
}
