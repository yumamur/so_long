#include "so_long.h"

void	run_game(t_game *game);
void	state_playing(int key, t_game *game);
void	state_pause(t_game *game);
void	state_restart(t_game *game);

int	handle_playing(int key, t_game *game)
{
	if (key == game->keybinds.up || key == game->keybinds.down
		|| key == game->keybinds.left || key == game->keybinds.right
		|| key == game->keybinds.attack || key == game->keybinds.block)
		state_playing(key, game);
	else if (key == game->keybinds.exit)
		exit_game(game, 0);
	else if (key == game->keybinds.pause)
		state_pause(game);
	else if (key == game->keybinds.restart)
		state_restart(game);
	display_game(game);
	return (0);
}

int	handle_restart(int key, t_game *game)
{
	if (key == game->keybinds.enter)
	{
		game->draw = 0;
		run_game(game);
	}
	else if (key == game->keybinds.restart)
		mlx_hook(game->win, 2, 1L << 0, handle_playing, game);
	return (0);
}

int	handle_pause(int key, t_game *game)
{
	if (key == game->keybinds.pause)
		mlx_hook(game->win, 2, 1L << 0, handle_playing, game);
	return (0);
}

int	handle_failure(int key, t_game *game)
{
	if (key == game->keybinds.enter)
		run_game(game);
	else if (key == game->keybinds.exit)
		exit_game(game, 0);
	return (0);
}

int	handle_success(int key, t_game *game)
{
	if (key == game->keybinds.enter)
		run_game(game);
	else if (key == game->keybinds.exit)
		exit_game(game, 0);
	return (0);
}
