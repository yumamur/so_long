#include "so_long.h"

void	run_game(t_game *game);
void	display_pause(t_game *game);
int		state_playing(int key, t_game *game);
int		state_pause(t_game *game);
int		state_restart(t_game *game);
int		substate_change_mode(t_game *game);
int		substate_exit(t_game *game);
int		substate_restart(t_game *game);
int		substate_resume(t_game *game);

int	handle_mouse_playing(int key, int x, int y, t_game *game)
{
	if (is_inside((t_coordinate){x, y},
		&(t_object){0, 0, game->data.padding, &game->img.map, 0}))
	{
		if (key == 1)
			state_playing(game->keybinds.attack, game);
		else if (key == 2)
			state_playing(game->keybinds.block, game);
		else if (key == 3)
			state_playing(calc_direction((t_coordinate){x, y}, game), game);
	}
	else
		state_pause(game);
	return (0);
}

int	handle_mouse_restart(int key, int x, int y, t_game *game)
{
	if (!(key >= 1 && key <= 3))
		return (0);
	else if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.origin.pos.x + 81,
		game->menu.origin.pos.y + 161}, &(t_xpm){99, 30, 0, 0}, 0}))
		run_game(game);
	else if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.origin.pos.x + 329,
		game->menu.origin.pos.y + 161}, &(t_xpm){80, 30, 0, 0}, 0})
		|| !is_inside((t_coordinate){x, y}, &game->menu.origin))
		substate_resume(game);
	return (0);
}

int	handle_mouse_pause(int key, int x, int y, t_game *game)
{
	if (!(key >= 1 && key <= 3))
		return (0);
	if (((is_inside((t_coordinate){x, y}, &(t_object){0, 0, game->data.padding,
				&game->img.map, 0}) && !is_inside((t_coordinate){x, y},
		&game->menu.origin)) || is_inside((t_coordinate){x, y}, &(t_object){
		0, 0, (t_coordinate){game->menu.origin.pos.x + 65,
		game->menu.origin.pos.y + 144}, &(t_xpm){72, 70, 0, 0}, 0}))
		&& substate_resume(game))
		game->menu.cur = RESUME;
	else if ((is_inside((t_coordinate){x, y}, &(t_object){0, 0,
			(t_coordinate){game->menu.origin.pos.x + 173,
			game->menu.origin.pos.y + 144}, &(t_xpm){72, 70, 0, 0}, 0})
		&& substate_restart(game)))
		game->menu.cur = RESTART;
	else if ((is_inside((t_coordinate){x, y}, &(t_object){0, 0,
			(t_coordinate){game->menu.origin.pos.x + 281,
			game->menu.origin.pos.y + 144}, &(t_xpm){72, 70, 0, 0}, 0}))
		&& substate_change_mode(game))
		game->menu.cur = MODE;
	else if ((is_inside((t_coordinate){x, y}, &(t_object){0, 0,
			(t_coordinate){game->menu.origin.pos.x + 399,
			game->menu.origin.pos.y + 144}, &(t_xpm){72, 70, 0, 0}, 0}))
		&& substate_exit(game))
		game->menu.cur = EXIT;
	return (0);
}

int	handle_mouse_end(int key, int x, int y, t_game *game)
{
	if (!(key >= 1 && key <= 3))
		return (0);
	if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.origin.pos.x + 164,
		game->menu.origin.pos.y + 206}, &(t_xpm){81, 34, 0, 0}, 0}))
		run_game(game);
	else if (is_inside((t_coordinate){x, y}, &(t_object){0, 0,
		(t_coordinate){game->menu.origin.pos.x + 264,
		game->menu.origin.pos.y + 206}, &(t_xpm){68, 34, 0, 0}, 0}))
		exit_game(game, 0);
	return (0);
}
