#include "so_long.h"

int	generate_obj(t_data *data)
{
	data->player = data->tmp_player;
	data->ct_clct = data->tmp_ct_clct;
	data->clct = malloc(sizeof(t_object) * data->ct_clct);
	if (!data->clct)
		return (SLE_OBJMALLOC);
	ft_memcpy(data->clct, data->tmp_clct, sizeof(t_object) * data->ct_clct);
}

void	run_game(t_game *game)
{
	generate_obj(&game);
	game->data.movect = 0;
	game->win = mlx_new_window(game->mlx, game->res.w, game->res.h, "so_long");
	mlx_do_key_autorepeatoff(game->mlx);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, handle_key_events, game);
	mlx_expose_hook(game->win, display_game, game);
	mlx_loop(game->mlx);
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
	int		errno;

	errno = map_generate(&game.data, argv[argc - 1]);
	if (errno)
		handle_error(errno, NULL);
	settings_default(&game);
	set_assets(&game);
	run_game(&game);
}
