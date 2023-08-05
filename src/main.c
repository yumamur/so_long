#include "so_long.h"

void	run_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		handle_error(SLE_MLXINIT, game);
	game->win = mlx_new_window(game->mlx, game->res.width, game->res.height, "game");
	mlx_do_key_autorepeatoff(game->mlx);
}

void	settings_default(t_game *game)
{
	game->res = (t_resolution){800, 600};
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
	// info(&game.data);
	set_assets(&game);
	run_game(&game);
	game.data.exit.crd = (t_coordinate){0, 0};
	mlx_hook(game.win, 17, 0, &exit_game, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_key_events, &game);
	mlx_loop(game.mlx);
}
