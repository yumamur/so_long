#include "so_long.h"
#include <mlx.h>

void	run_game(t_game *game)
{
	int	a = 16;
	mlx_do_key_autorepeatoff(game->mlx);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "game");
	// game->data.player.img = mlx_xpm_file_to_image(game->mlx, "/home/yusuf/Desktop/so_long/ghost.xpm", &a, &a);
	game->data.player.img = NULL;
	game->data.exit.img = mlx_xpm_file_to_image(game->mlx, "/home/yusuf/Desktop/so_long/background.xpm", &a, &a);
	// game->data.exit.img = NULL;
	game->lst_img.arr = NULL;
}

void	bind_default(t_bind *bind)
{
	bind->right = K_RIGHT;
	bind->left = K_LEFT;
	bind->up = K_UP;
	bind->down = K_DOWN;
	bind->esc = K_ESC;
	bind->pause = K_P;

}

int	main(int argc, char *argv[])
{
	t_game	game;

	map_generate(&game.data, argv[argc - 1]);
	graph_align(&game.data.pad, &game.data.map.size);
	info(&game.data);
	bind_default(&game.keybinds);
	game.mlx = mlx_init();
	run_game(&game);
	game.data.exit.crd = (t_coordinate){0, 0};
	mlx_hook(game.win, 17, 0, &exit_game, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_key_events, &game);
	mlx_loop(game.mlx);
}
