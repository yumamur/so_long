#include "so_long.h"

void	run_game(t_game *game);
void	display_pause(t_game *game);
void	state_playing(int key, t_game *game);
void	state_pause(t_game *game);
void	state_restart(t_game *game);
void	substate_change_mode(t_game *game);
void	substate_exit(t_game *game);
void	substate_restart(t_game *game);
void	substate_resume(t_game *game);

int	handle_mouse_playing(int key, int x, int y, t_game *game)
{
	if (is_inside((t_coordinate){x, y}, &(t_object){.img = &game->img.map,
			.pos = game->data.padding}))
	{
		if (key == 1)
			state_playing(game->keybinds.attack, game);
		else if (key == 2)
			state_playing(game->keybinds.block, game);
		else if (key == 3)
			state_playing(calc_direction((t_coordinate){x, y}, game), game);
	}
	else if (key == game->keybinds.exit)
		exit_game(game, 0);
	else if (key == game->keybinds.pause)
	{
		game->menu.cur = RESUME;
		state_pause(game);
	}
	else if (key == game->keybinds.restart)
		state_restart(game);
	return (0);
}

int	handle_mouse_restart(int key,/*  int x, int y, */ t_game *game)
{
	if (key == game->keybinds.enter || key == game->keybinds.restart)
		run_game(game);
	else if (key == game->keybinds.exit)
		substate_resume(game);
	return (0);
}

int	handle_mouse_pause(int key,/*  int x, int y,  */t_game *game)
{
	if (key == game->keybinds.pause || key == game->keybinds.exit)
		substate_resume(game);
	else if (key == game->keybinds.left && game->menu.cur > 0)
	{
		--game->menu.cur;
		display_pause(game);
	}
	else if (key == game->keybinds.right && game->menu.cur < 3)
	{
		++game->menu.cur;
		display_pause(game);
	}
	else if (key == game->keybinds.enter)
	{
		if (game->menu.cur == RESUME)
			substate_resume(game);
		else if (game->menu.cur == RESTART)
			substate_restart(game);
		else if (game->menu.cur == MODE)
			substate_change_mode(game);
		else if (game->menu.cur == EXIT)
			substate_exit(game);
	}
	return (0);
}

int	handle_mouse_end(int key,/*  int x, int y,  */t_game *game)
{
	if (key == game->keybinds.enter)
		run_game(game);
	else if (key == game->keybinds.exit)
		exit_game(game, 0);
	return (0);
}
