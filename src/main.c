#include "so_long.h"

int		map_generate(t_data *data, char *map_name);
void	set_assets(t_game *game);

int	generate_obj(t_data *data)
{
	data->player = data->tmp_player;
	data->ct_clct = data->tmp_ct_clct;
	if (data->clct)
		free(data->clct);
	data->clct = malloc(sizeof(t_object) * data->ct_clct);
	if (!data->clct)
		return (SLE_OBJMALLOC);
	ft_memcpy(data->clct, data->tmp_clct, sizeof(t_object) * data->ct_clct);
	return (0);
}

#ifdef SO_LONG_BONUS

void	run_game(t_game *game)
{
	int	errno;

	mlx_clear_window(game->mlx, game->win);
	game->data.movect = 0;
	errno = generate_obj(&game->data);
	if (errno)
		handle_error(errno, game);
	game->data.movect = 0;
	mlx_do_key_autorepeaton(game->mlx);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, handle_key_events, game);
	mlx_loop_hook(game->win, display_game, game);
	display_game(game);
	mlx_loop(game->mlx);
}

#else

void	run_game(t_game *game)
{
	int	errno;

	mlx_clear_window(game->mlx, game->win);
	game->data.movect = 0;
	errno = generate_obj(&game->data);
	if (errno)
		handle_error(errno, game);
	game->data.movect = 0;
	mlx_do_key_autorepeaton(game->mlx);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_hook(game->win, 2, 1L << 0, handle_key_events, game);
	mlx_expose_hook(game->win, display_game, game);
	display_game(game);
	mlx_loop(game->mlx);
}
#endif

void	settings_default(t_game *game)
{
	game->res = (t_resolution){1368, 768};
	game->keybinds.right = K_RIGHT;
	game->keybinds.left = K_LEFT;
	game->keybinds.up = K_UP;
	game->keybinds.down = K_DOWN;
	game->keybinds.attack = K_SPACE;
	game->keybinds.exit = K_ESC;
	game->keybinds.enter = K_ENTER;
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
	game.win = mlx_new_window(game.mlx, game.res.w, game.res.h, "so_long");
	run_game(&game);
}
