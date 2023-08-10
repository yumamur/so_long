#include "so_long.h"

void	draw_background(t_game *game, t_coordinate crd);

int	handle_key_events(int key, t_game *game)
{
	if (key == game->keybinds.up || key == game->keybinds.down
		|| key == game->keybinds.left || key == game->keybinds.right)
	{
		draw_background(game, game->data.player.pos);
		object_p_move(game, &game->data.player, key);
	}
	else if (key == game->keybinds.esc)
		exit_game(game, 0);
	display_game(game);
	return (0);
}
