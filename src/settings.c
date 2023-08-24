#include "so_long.h"

void	settings_default(t_game *game)
{
	game->res = (t_resolution){SL_RES_WIDTH, SL_RES_HEIGHT};
	game->keybinds.right = K_RIGHT;
	game->keybinds.left = K_LEFT;
	game->keybinds.up = K_UP;
	game->keybinds.down = K_DOWN;
	game->keybinds.attack = K_SPACE;
	game->keybinds.exit = K_ESC;
	game->keybinds.enter = K_ENTER;
	game->keybinds.pause = K_P;
	game->keybinds.restart = K_R;
	game->mode = HARD;
}
