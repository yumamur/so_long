#include "so_long.h"
#include <mlx.h>

int	main(int argc, char *argv[])
{
	t_game	game;

	game.data.map.name = argv[argc - 1];
	map_init(&game);
	printf("after init\n");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "game");
	mlx_hook(game.win, 2, 1L << 0, handle_key_events, &game);
	mlx_loop(game.mlx);
}
