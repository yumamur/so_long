#include "so_long.h"

void	run_game(t_game *game);
int		state_pause(t_game *game);
int		substate_exit(t_game *game);
int		substate_restart(t_game *game);
int		substate_change_mode(t_game *game);
int		handle_sub_change_mode(int key, t_game *game);
int		change_mode_restart(int key, t_game *game);
void	display_change_mode_diff(t_game *game, int delta);

int	handle_mouse_sub_change_mode(int key, int x, int y, t_game *game)
{
	if (!(key >= 1 && key <= 3))
		return (0);
	if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.chmod.pos.x + 73,
		game->menu.chmod.pos.y + 104}, &(t_xpm){23, 38, 0, 0}, 0}))
		handle_sub_change_mode(game->keybinds.left, game);
	else if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.chmod.pos.x + 217,
		game->menu.chmod.pos.y + 102}, &(t_xpm){31, 36, 0, 0}, 0}))
		handle_sub_change_mode(game->keybinds.right, game);
	else if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.chmod.pos.x + 133,
		game->menu.chmod.pos.y + 206}, &(t_xpm){77, 30, 0, 0}, 0}))
		handle_sub_change_mode(game->keybinds.enter, game);
	else if (!is_inside((t_coordinate){x, y}, &game->menu.chmod)
		|| is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.chmod.pos.x + 273,
		game->menu.chmod.pos.y + 215}, &(t_xpm){49, 24, 0, 0}, 0}))
		handle_sub_change_mode(game->keybinds.exit, game);
	return (0);
}

int	handle_mouse_sub_restart(int key, int x, int y, t_game *game)
{
	if (!(key >= 1 && key <= 3))
		return (0);
	if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.origin.pos.x + 81,
		game->menu.origin.pos.y + 161}, &(t_xpm){99, 30, 0, 0}, 0}))
		run_game(game);
	else if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.origin.pos.x + 329,
		game->menu.origin.pos.y + 161}, &(t_xpm){80, 30, 0, 0}, 0})
		|| !is_inside((t_coordinate){x, y}, &game->menu.origin))
		state_pause(game);
	return (0);
}

int	handle_mouse_sub_exit(int key, int x, int y, t_game *game)
{
	if (!(key >= 1 && key <= 3))
		return (0);
	if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.origin.pos.x + 81,
		game->menu.origin.pos.y + 161}, &(t_xpm){99, 30, 0, 0}, 0}))
		exit_game(game, 0);
	else if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.origin.pos.x + 329,
		game->menu.origin.pos.y + 161}, &(t_xpm){80, 30, 0, 0}, 0})
		|| !is_inside((t_coordinate){x, y}, &game->menu.origin))
		state_pause(game);
	return (0);
}
