#include "so_long.h"
#include <mlx.h>

int	main(int argc, char *argv[])
{
	t_game	game;
	int a = 32;

	map_generate(&game.data, argv[argc - 1]);
	printf("after init\n");
	game.mlx = mlx_init();
	game.data.player.img = mlx_xpm_file_to_image(game.mlx, "~/Desktop/so_long/32x32Template.xpm", &a, &a);
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "game");
	mlx_hook(game.win, 2, 1L << 0, handle_key_events, &game);
	mlx_loop(game.mlx);
}
