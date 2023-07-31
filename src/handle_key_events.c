#include "so_long.h"

int move_player(t_game *game, int key);

int	handle_key_events(int key, t_game *game)
{
	if (key == K_ESC)
		exit_game(game);
	if (key == K_RIGHT || key == K_LEFT || key == K_DOWN || key == K_UP)
		move_player(game, key);
	return (0);
}
