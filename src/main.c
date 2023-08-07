#include "so_long.h"

void	run_game(t_game *game)
{
	set_assets(game);
	game->win = mlx_new_window(game->mlx, game->res.w, game->res.h, "so_long");
	mlx_do_key_autorepeatoff(game->mlx);
}

void	settings_default(t_game *game)
{
	game->res = (t_resolution){1368, 768};
	game->keybinds.right = K_RIGHT;
	game->keybinds.left = K_LEFT;
	game->keybinds.up = K_UP;
	game->keybinds.down = K_DOWN;
	game->keybinds.esc = K_ESC;
	game->keybinds.pause = K_P;
	game->keybinds.restart = K_R;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	import_map(&game.data, argv[argc - 1]);
	settings_default(&game);
	run_game(&game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_key_events, &game);
	mlx_expose_hook(game.win, display_game, &game);
	// mlx_loop_hook(game.mlx, display_game, &game);
	mlx_loop(game.mlx);
}
