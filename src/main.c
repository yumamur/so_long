#include "so_long.h"
#include <mlx.h>

int	main()
{
	t_game	game;
	int	a = 32;

	// map_init(&game, argv[argc - 1]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "game");
	game.img_lst.ptr = mlx_xpm_file_to_image(game.mlx, "../32x32Template.xpm", &a, &a);
	mlx_hook(game.win, 2, 1L << 0, handle_key_events, 0);
	mlx_loop(game.mlx);
}
